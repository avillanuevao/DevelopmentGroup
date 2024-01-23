#include <memory>

#include <gtest/gtest.h>

#include <model/AllFunds.hpp>

class AllModelUnitTest : public testing::Test
{
    public:
        AllModelUnitTest();
        virtual ~AllModelUnitTest();

        virtual void SetUp() override;
        virtual void TearDown() override;

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

AllModelUnitTest::AllModelUnitTest()
{

}

AllModelUnitTest::~AllModelUnitTest()
{

}

void AllModelUnitTest::SetUp()
{
    m_allFunds.reset(new model::AllFunds());
}

void AllModelUnitTest::TearDown()
{
    m_allFunds.reset();
}

/**
 * @unittest Test of AllModelUnitTest
 */
TEST_F(AllModelUnitTest, prueba)
{
    EXPECT_EQ("a", "a");
}
