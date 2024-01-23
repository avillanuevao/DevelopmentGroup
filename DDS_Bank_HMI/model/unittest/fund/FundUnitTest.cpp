#include <memory>

#include <gtest/gtest.h>

#include <Fund.hpp>

const int INITAMOUNT = 1000;

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

TEST_P(FundUnitTest, getFundType)
{
    model::FundType fundTypeExpected = GetParam();
    model::FundType fundType = m_fund->getFundType();

    ASSERT_EQ(fundTypeExpected, fundType);
}

/**
 * @unittest Test of FundUnitTest
 */

TEST_P(FundUnitTest, getAmount)
{
    int amountOutput = m_fund->getAmount();

    ASSERT_EQ(INITAMOUNT, amountOutput);
}

/**
 * @unittest Test of FundUnitTest
 */

TEST_P(FundUnitTest, setAmount)
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
    int amountInput = -2000;

    //TODO: CAMBIAR A ASSERT
    EXPECT_ANY_THROW(m_fund->setAmount(amountInput));
}

/**
 * @unittest Test of FundUnitTest
 */

TEST_P(FundUnitTest, increaseAmount)
{
    int amountInput = 2000;
    int amountExpected = INITAMOUNT + amountInput;

    m_fund->increaseAmount(amountInput);
    int amountOutput = m_fund->getAmount();

    ASSERT_EQ(amountExpected, amountOutput);

}

/**
 * @unittest Test of FundUnitTest
 */

TEST_P(FundUnitTest, increaseAmountNegative)
{
    int amountInput = -2000;

    ASSERT_ANY_THROW(m_fund->increaseAmount(amountInput));
}

