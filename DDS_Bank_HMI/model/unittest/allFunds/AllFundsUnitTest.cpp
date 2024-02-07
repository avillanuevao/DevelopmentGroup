#include <memory>

#include <gtest/gtest.h>

#include <AllFunds.hpp>

const int AMOUNTZERO = 0;
const int AMOUNT01 = 500;
const int AMOUNT02 = 1000;
const int AMOUNTNEGATIVE = -2000;

class AllFundsUnitTest : public testing::TestWithParam<model::operations::FundType>
{
    public:
        AllFundsUnitTest();
        virtual ~AllFundsUnitTest();
    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;

        std::shared_ptr<model::operations::AllFunds> m_allFunds;
        model::operations::FundType m_fundType;
};

INSTANTIATE_TEST_CASE_P(FundTypes, AllFundsUnitTest, testing::Values(model::operations::FundType::SAVINGS, model::operations::FundType::HOUSING));


AllFundsUnitTest::AllFundsUnitTest()
{

}

AllFundsUnitTest::~AllFundsUnitTest()
{

}

void AllFundsUnitTest::SetUp()
{
    m_allFunds.reset(new model::operations::AllFunds());
    m_fundType = GetParam();
}

void AllFundsUnitTest::TearDown()
{
    m_allFunds.reset();
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, getAmountOK)
{
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_EQ(AMOUNTZERO, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, getAmountNotOK)
{
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_NE(AMOUNT01, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, setAmountOK)
{
    m_allFunds->setAmount(m_fundType, AMOUNT01);
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_EQ(AMOUNT01, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, setAmountNotOK)
{
    m_allFunds->setAmount(m_fundType, AMOUNT01);
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_NE(AMOUNT02, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, setAmountNegative)
{
    ASSERT_THROW(m_allFunds->setAmount(m_fundType, AMOUNTNEGATIVE), std::logic_error);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, increaseAmountOK)
{    
    int amountExpected = m_allFunds->getAmount(m_fundType) + AMOUNT01;

    for(int i = 0; i < 5; i++)
    {
        m_allFunds->increaseAmount(m_fundType, AMOUNT01);
        int amountOutput = m_allFunds->getAmount(m_fundType);

        ASSERT_EQ(amountExpected, amountOutput);

        amountExpected += AMOUNT01;
    }

}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, increaseAmountNegative)
{

    ASSERT_THROW(m_allFunds->increaseAmount(m_fundType, AMOUNTNEGATIVE), std::logic_error);
}
