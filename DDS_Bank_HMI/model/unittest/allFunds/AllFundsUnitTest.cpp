#include <memory>
#include <vector>

#include <gtest/gtest.h>

#include <operations/AllFunds.hpp>

const int kAmountZero = 0;
const int kAmount01 = 500;
const int kAmount02 = 1000;
const int kAmountBig = 10000;
const int kAmountNegative = -2000;

class AllFundsUnitTest :
    public testing::TestWithParam<std::tuple<model::operations::kFundType, model::operations::kFundType>>
{
  public:
    AllFundsUnitTest();
    virtual ~AllFundsUnitTest();
  protected:
    virtual void SetUp() override;
    virtual void TearDown() override;

    std::shared_ptr<model::operations::AllFunds> mAllFunds;
    model::operations::kFundType mActualFundType;
    model::operations::kFundType mOtherFundType;
};

INSTANTIATE_TEST_CASE_P(FundTypesOK, AllFundsUnitTest, testing::Values(
                          std::make_tuple(model::operations::kFundType::Savings,
                                          model::operations::kFundType::Housing),
                          std::make_tuple(model::operations::kFundType::Housing,
                                          model::operations::kFundType::Savings)));

AllFundsUnitTest::AllFundsUnitTest():
  mActualFundType(std::get<0>(GetParam())),
  mOtherFundType(std::get<1>(GetParam()))
{

}

AllFundsUnitTest::~AllFundsUnitTest()
{

}

void AllFundsUnitTest::SetUp()
{
  mActualFundType = std::get<0>(GetParam());
  mOtherFundType = std::get<1>(GetParam());
  mAllFunds.reset(new model::operations::AllFunds(mActualFundType));
}

void AllFundsUnitTest::TearDown()
{
  mAllFunds.reset();
}

TEST_P(AllFundsUnitTest, getAmountByFundType)
{
  int amountOutput = mAllFunds->getAmount(mActualFundType);

  ASSERT_EQ(kAmountZero, amountOutput);

  amountOutput = mAllFunds->getAmount(mOtherFundType);

  ASSERT_EQ(kAmountZero, amountOutput);
}

TEST_P(AllFundsUnitTest, getAmount)
{
  int amountOutput = mAllFunds->getAmount();

  ASSERT_EQ(kAmountZero, amountOutput);
}

TEST_P(AllFundsUnitTest, setAmountByFundType)
{
  mAllFunds->setAmount(mActualFundType, kAmount01);
  int amountOutput = mAllFunds->getAmount(mActualFundType);

  ASSERT_EQ(kAmount01, amountOutput);

  mAllFunds->setAmount(mOtherFundType, kAmount02);
  int amountOutputOther = mAllFunds->getAmount(mOtherFundType);

  ASSERT_EQ(kAmount02, amountOutputOther);
  ASSERT_NE(amountOutput, amountOutputOther);
}

TEST_P(AllFundsUnitTest, setAmount)
{
  mAllFunds->setAmount(kAmount01);
  int amountOutput = mAllFunds->getAmount();

  ASSERT_EQ(kAmount01, amountOutput);

  int amountOther = mAllFunds->getAmount(mOtherFundType);
  ASSERT_NE(amountOutput, amountOther);
}

TEST_P(AllFundsUnitTest, setAmountNegativeByFundType)
{
  ASSERT_THROW(mAllFunds->setAmount(mActualFundType, kAmountNegative), std::logic_error);
}

TEST_P(AllFundsUnitTest, setAmountNegative)
{
  ASSERT_THROW(mAllFunds->setAmount(kAmountNegative), std::logic_error);
}

TEST_P(AllFundsUnitTest, increaseAmountOK)
{    
  int amountExpected = mAllFunds->getAmount() + kAmount01;

  for(int i = 0; i < 5; i++)
  {
    mAllFunds->increaseAmount(kAmount01);
    int amountOutput = mAllFunds->getAmount();

    ASSERT_EQ(amountExpected, amountOutput);
    ASSERT_NE(mAllFunds->getAmount(mOtherFundType), amountOutput);
    amountExpected += kAmount01;
  }

}

TEST_P(AllFundsUnitTest, increaseAmountNegative)
{

  ASSERT_THROW(mAllFunds->increaseAmount(kAmountNegative), std::logic_error);
}

TEST_P(AllFundsUnitTest, decreaseAmountOK)
{
  mAllFunds->setAmount(kAmountBig);

  int amountExpected = mAllFunds->getAmount() - kAmount01;

  for(int i = 0; i < 5; i++)
  {
    mAllFunds->decreaseAmount(kAmount01);
    int amountOutput = mAllFunds->getAmount();

    ASSERT_EQ(amountExpected, amountOutput);
    ASSERT_NE(mAllFunds->getAmount(mOtherFundType), amountOutput);
    amountExpected -= kAmount01;
  }

}

TEST_P(AllFundsUnitTest, decreaseAmountNegative)
{
  ASSERT_THROW(mAllFunds->decreaseAmount(kAmountNegative), std::logic_error);
}

TEST_P(AllFundsUnitTest, decreaseAmountNotEnoughMoney)
{
  ASSERT_THROW(mAllFunds->decreaseAmount(kAmount01), std::logic_error);
}

TEST_P(AllFundsUnitTest, transferAmount)
{
  mAllFunds->setAmount(kAmountBig);

  int amountToTransfer = kAmount01;
  int amountOriginExpected = mAllFunds->getAmount() - amountToTransfer;
  int amountDestinationExpected = mAllFunds->getAmount(mOtherFundType) + amountToTransfer;

  mAllFunds->transferAmount(mOtherFundType, amountToTransfer);

  ASSERT_EQ(amountOriginExpected, mAllFunds->getAmount());
  ASSERT_EQ(amountDestinationExpected, mAllFunds->getAmount(mOtherFundType));
}

TEST_P(AllFundsUnitTest, transferAmountNegative)
{
  ASSERT_THROW(mAllFunds->transferAmount(mOtherFundType, kAmountNegative), std::logic_error);
}

TEST_P(AllFundsUnitTest, transferAmountNotEnoughMoney)
{
  ASSERT_THROW(mAllFunds->transferAmount(mOtherFundType, kAmount01), std::logic_error);
}
