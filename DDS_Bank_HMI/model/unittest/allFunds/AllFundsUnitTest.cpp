#include <memory>
#include <vector>

#include <gtest/gtest.h>

#include <operations/AllFunds.hpp>

const int AMOUNTZERO = 0;
const int AMOUNT01 = 500;
const int AMOUNT02 = 1000;
const int AMOUNTBIG = 10000;
const int AMOUNTNEGATIVE = -2000;

class AllFundsUnitTest : public testing::TestWithParam<std::tuple<model::operations::FundType, model::operations::FundType>>
{
    public:
        AllFundsUnitTest();
        virtual ~AllFundsUnitTest();
    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;

        std::shared_ptr<model::operations::AllFunds> m_allFunds;
        model::operations::FundType m_actualFundType;
        model::operations::FundType m_otherFundType;
//        std::vector<model::operations::FundType> m_funds {model::operations::FundType::SAVINGS, model::operations::FundType::HOUSING};
};

INSTANTIATE_TEST_CASE_P(FundTypesOK, AllFundsUnitTest, testing::Values(
                            std::make_tuple(model::operations::FundType::SAVINGS, model::operations::FundType::HOUSING),
                            std::make_tuple(model::operations::FundType::HOUSING, model::operations::FundType::SAVINGS)));

AllFundsUnitTest::AllFundsUnitTest()
{

}

AllFundsUnitTest::~AllFundsUnitTest()
{

}

void AllFundsUnitTest::SetUp()
{
    m_actualFundType = std::get<0>(GetParam());
    m_otherFundType = std::get<1>(GetParam());
    m_allFunds.reset(new model::operations::AllFunds(m_actualFundType));
}

void AllFundsUnitTest::TearDown()
{
    m_allFunds.reset();
}

TEST_P(AllFundsUnitTest, getAmountByFundType)
{
    int amountOutput = m_allFunds->getAmount(m_actualFundType);

    ASSERT_EQ(AMOUNTZERO, amountOutput);

    amountOutput = m_allFunds->getAmount(m_otherFundType);

    ASSERT_EQ(AMOUNTZERO, amountOutput);
}

TEST_P(AllFundsUnitTest, getAmount)
{
    int amountOutput = m_allFunds->getAmount();

    ASSERT_EQ(AMOUNTZERO, amountOutput);
}

TEST_P(AllFundsUnitTest, setAmountByFundType)
{
    m_allFunds->setAmount(m_actualFundType, AMOUNT01);
    int amountOutput = m_allFunds->getAmount(m_actualFundType);

    ASSERT_EQ(AMOUNT01, amountOutput);

    m_allFunds->setAmount(m_otherFundType, AMOUNT02);
    int amountOutputOther = m_allFunds->getAmount(m_otherFundType);

    ASSERT_EQ(AMOUNT02, amountOutputOther);
    ASSERT_NE(amountOutput, amountOutputOther);
}

TEST_P(AllFundsUnitTest, setAmount)
{
    m_allFunds->setAmount(AMOUNT01);
    int amountOutput = m_allFunds->getAmount();

    ASSERT_EQ(AMOUNT01, amountOutput);

    int amountOther = m_allFunds->getAmount(m_otherFundType);
    ASSERT_NE(amountOutput, amountOther);
}

TEST_P(AllFundsUnitTest, setAmountNegativeByFundType)
{
    ASSERT_THROW(m_allFunds->setAmount(m_actualFundType, AMOUNTNEGATIVE), std::logic_error);
}

TEST_P(AllFundsUnitTest, setAmountNegative)
{
    ASSERT_THROW(m_allFunds->setAmount(AMOUNTNEGATIVE), std::logic_error);
}

TEST_P(AllFundsUnitTest, increaseAmountOK)
{    
    int amountExpected = m_allFunds->getAmount() + AMOUNT01;

    for(int i = 0; i < 5; i++)
    {
        m_allFunds->increaseAmount(AMOUNT01);
        int amountOutput = m_allFunds->getAmount();

        ASSERT_EQ(amountExpected, amountOutput);
        ASSERT_NE(m_allFunds->getAmount(m_otherFundType), amountOutput);
        amountExpected += AMOUNT01;
    }

}

TEST_P(AllFundsUnitTest, increaseAmountNegative)
{

    ASSERT_THROW(m_allFunds->increaseAmount(AMOUNTNEGATIVE), std::logic_error);
}

TEST_P(AllFundsUnitTest, decreaseAmountOK)
{
    m_allFunds->setAmount(AMOUNTBIG);

    int amountExpected = m_allFunds->getAmount() - AMOUNT01;

    for(int i = 0; i < 5; i++)
    {
        m_allFunds->decreaseAmount(AMOUNT01);
        int amountOutput = m_allFunds->getAmount();

        ASSERT_EQ(amountExpected, amountOutput);
        ASSERT_NE(m_allFunds->getAmount(m_otherFundType), amountOutput);
        amountExpected -= AMOUNT01;
    }

}

TEST_P(AllFundsUnitTest, decreaseAmountNegative)
{

    ASSERT_THROW(m_allFunds->decreaseAmount(AMOUNTNEGATIVE), std::logic_error);
}

TEST_P(AllFundsUnitTest, decreaseAmountNotEnoughMoney)
{

    ASSERT_THROW(m_allFunds->decreaseAmount(AMOUNT01), std::logic_error);
}

TEST_P(AllFundsUnitTest, transferAmount)
{
    m_allFunds->setAmount(AMOUNTBIG);

    int amountToTransfer = AMOUNT01;
    int amountOriginExpected = m_allFunds->getAmount() - amountToTransfer;
    int amountDestinationExpected = m_allFunds->getAmount(m_otherFundType) + amountToTransfer;

    m_allFunds->transferAmount(m_otherFundType, amountToTransfer);

    ASSERT_EQ(amountOriginExpected, m_allFunds->getAmount());
    ASSERT_EQ(amountDestinationExpected, m_allFunds->getAmount(m_otherFundType));
}

TEST_P(AllFundsUnitTest, transferAmountNegative)
{

    ASSERT_THROW(m_allFunds->transferAmount(m_otherFundType, AMOUNTNEGATIVE), std::logic_error);
}

TEST_P(AllFundsUnitTest, transferAmountNotEnoughMoney)
{

    ASSERT_THROW(m_allFunds->transferAmount(m_otherFundType, AMOUNT01), std::logic_error);
}
