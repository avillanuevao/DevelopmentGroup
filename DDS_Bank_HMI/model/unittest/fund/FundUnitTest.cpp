#include <memory>

#include <gtest/gtest.h>

#include <operations/Fund.hpp>

const int kInitAmount = 1000;
const int kAmount01 = 500;
const int kAmountNegative = -2000;

class FundUnitTest :
    public testing::TestWithParam<model::operations::kFundType>
{
  public:
    FundUnitTest();
    virtual ~FundUnitTest();

  protected:
    virtual void SetUp() override;
    virtual void TearDown() override;

    std::shared_ptr<model::operations::Fund> mFund;
};

INSTANTIATE_TEST_CASE_P(FundTypes, FundUnitTest, testing::Values(model::operations::kFundType::Savings,
                                                                 model::operations::kFundType::Housing));

FundUnitTest::FundUnitTest()
{

}

FundUnitTest::~FundUnitTest()
{

}

void FundUnitTest::SetUp()
{
  mFund.reset(new model::operations::Fund(GetParam(), kInitAmount));
}

void FundUnitTest::TearDown()
{
  mFund.reset();
}


TEST_P(FundUnitTest, getFundType)
{
  model::operations::kFundType fundTypeExpected = GetParam();
  model::operations::kFundType fundType = mFund->getFundType();

  ASSERT_EQ(fundTypeExpected, fundType);
}

TEST_P(FundUnitTest, getAmountInitAmount)
{
  int amountOutput = mFund->getAmount();

  ASSERT_EQ(kInitAmount, amountOutput);
}

TEST_P(FundUnitTest, setAmount)
{
  int amountInput = 2000;

  mFund->setAmount(amountInput);
  int amountOutput = mFund->getAmount();

  ASSERT_EQ(amountInput, amountOutput);
  ASSERT_NE(kInitAmount, amountOutput);

}

TEST_P(FundUnitTest, setAmountNegative)
{
  ASSERT_THROW(mFund->setAmount(kAmountNegative), std::logic_error);
}

TEST_P(FundUnitTest, increaseAmountOK)
{
  int amountInput = 2000;
  int amountExpected = kInitAmount + amountInput;

  for(int i = 0; i < 5; i++)
  {
    mFund->increaseAmount(amountInput);
    int amountOutput = mFund->getAmount();

    ASSERT_EQ(amountExpected, amountOutput);

    amountExpected += amountInput;
  }

}

TEST_P(FundUnitTest, increaseAmountNotOK)
{
  int amountInput = 2000;
  int amountNotExpected = kInitAmount;

  for(int i = 0; i < 5; i++)
  {
    mFund->increaseAmount(amountInput);
    int amountOutput = mFund->getAmount();

    ASSERT_NE(amountNotExpected, amountOutput);

    amountNotExpected += amountInput;
  }
}

TEST_P(FundUnitTest, increaseAmountNegative)
{
  ASSERT_THROW(mFund->increaseAmount(kAmountNegative), std::logic_error);
}

TEST_P(FundUnitTest, decreaseAmountOK)
{
  int amountInput = 10;
  int amountExpected = kInitAmount - amountInput;

  for(int i = 0; i < 5; i++)
  {
    mFund->decreaseAmount(amountInput);
    int amountOutput = mFund->getAmount();

    ASSERT_EQ(amountExpected, amountOutput);

    amountExpected -= amountInput;
  }

}

TEST_P(FundUnitTest, decreaseAmountNotOK)
{
  int amountInput = 10;
  int amountNotExpected = kInitAmount;

  for(int i = 0; i < 5; i++)
  {
    mFund->decreaseAmount(amountInput);
    int amountOutput = mFund->getAmount();

    ASSERT_NE(amountNotExpected, amountOutput);

    amountNotExpected -= amountInput;
  }
}

TEST_P(FundUnitTest, decreaseAmountNegative)
{
  ASSERT_THROW(mFund->decreaseAmount(kAmountNegative), std::logic_error);
}
