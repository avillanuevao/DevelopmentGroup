#include <memory>

#include <gtest/gtest.h>

#include <AllFunds.hpp>

class AllFundsUnitTest : public testing::TestWithParam<model::FundType>
{
    public:
        AllFundsUnitTest();
        virtual ~AllFundsUnitTest();
    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;

        std::shared_ptr<model::AllFunds> m_allFunds;
        model::FundType m_fundType;
};

INSTANTIATE_TEST_CASE_P(FundTypes, AllFundsUnitTest, testing::Values(model::FundType::SAVINGS, model::FundType::HOUSING));


AllFundsUnitTest::AllFundsUnitTest()
{

}

AllFundsUnitTest::~AllFundsUnitTest()
{

}

void AllFundsUnitTest::SetUp()
{
    m_allFunds.reset(new model::AllFunds());
    m_fundType = GetParam();
}

void AllFundsUnitTest::TearDown()
{
    m_allFunds.reset();
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, getAmount)
{
    int amountExpected = 0;
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_EQ(amountExpected, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, setAmount)
{
    int newAmount = 2000;

    m_allFunds->setAmount(m_fundType, newAmount);
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_EQ(newAmount, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, setAmountNegative)
{
    int newAmount = -2000;

    //TODO: CAMBIAR A ASSERT
    EXPECT_ANY_THROW(m_allFunds->setAmount(m_fundType, newAmount));
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, increaseAmount)
{
    int newAmount = 2000;
    int amountExpected = m_allFunds->getAmount(m_fundType) + newAmount;

    m_allFunds->increaseAmount(m_fundType, newAmount);
    int amountOutput = m_allFunds->getAmount(m_fundType);

    ASSERT_EQ(amountExpected, amountOutput);
}

/**
 * @unittest Test of AllFundsUnitTest
 */

TEST_P(AllFundsUnitTest, increaseAmountNegative)
{
    int newAmount = -2000;

    //TODO: CAMBIAR A ASSERT
    EXPECT_ANY_THROW(m_allFunds->increaseAmount(m_fundType, newAmount));
}
