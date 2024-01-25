#include <memory>

#include <gtest/gtest.h>

#include <Fund.hpp>

const int INITAMOUNT = 1000;
const int AMOUNT01 = 500;
const int AMOUNTNEGATIVE = -2000;

class FundUnitTest : public testing::TestWithParam<model::FundType>
{
    public:
        FundUnitTest();
        virtual ~FundUnitTest();

    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;
        std::shared_ptr<model::Fund> m_fund;
    private:

};

INSTANTIATE_TEST_CASE_P(FundTypes, FundUnitTest, testing::Values(model::FundType::SAVINGS, model::FundType::HOUSING));

FundUnitTest::FundUnitTest()
{

}

FundUnitTest::~FundUnitTest()
{

}

void FundUnitTest::SetUp()
{
    m_fund.reset(new model::Fund(GetParam(), INITAMOUNT));
}

void FundUnitTest::TearDown()
{
    m_fund.reset();
}


/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, getFundTypeOK)
{
    model::FundType fundTypeExpected = GetParam();
    model::FundType fundType = m_fund->getFundType();

    ASSERT_EQ(fundTypeExpected, fundType);
}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, getFundTypeNotOK)
{
    model::FundType fundTypeExpected = model::FundType::NONE;
    model::FundType fundType = m_fund->getFundType();

    ASSERT_NE(fundTypeExpected, fundType);
}


/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, getAmountInitAmountOK)
{
    int amountOutput = m_fund->getAmount();

    ASSERT_EQ(INITAMOUNT, amountOutput);
}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, getAmountInitAmountNotOK)
{
    int amountOutput = m_fund->getAmount();

    ASSERT_NE(AMOUNT01, amountOutput);
}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, setAmountOK)
{
    int amountInput = 2000;

    m_fund->setAmount(amountInput);
    int amountOutput = m_fund->getAmount();

    ASSERT_EQ(amountInput, amountOutput);

}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, setAmountNegative)
{
    ASSERT_THROW(m_fund->setAmount(AMOUNTNEGATIVE), std::logic_error);
}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, setAmountNotOK)
{
    int amountInput = 2000;

    m_fund->setAmount(amountInput);
    int amountOutput = m_fund->getAmount();

    ASSERT_NE(AMOUNT01, amountOutput);

}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, increaseAmountOK)
{
    int amountInput = 2000;
    int amountExpected = INITAMOUNT + amountInput;

    for(int i = 0; i < 5; i++)
    {
        m_fund->increaseAmount(amountInput);
        int amountOutput = m_fund->getAmount();

        ASSERT_EQ(amountExpected, amountOutput);

        amountExpected += amountInput;
    }

}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, increaseAmountNotOK)
{
    m_fund->increaseAmount(AMOUNT01);
    int amountOutput = m_fund->getAmount();

    ASSERT_NE(AMOUNT01, amountOutput);

}

/**
 * @unittest Test of FundUnitTest
 */
TEST_P(FundUnitTest, increaseAmountNegative)
{
    ASSERT_THROW(m_fund->increaseAmount(AMOUNTNEGATIVE), std::logic_error);
}

