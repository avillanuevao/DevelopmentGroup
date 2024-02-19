#include <gtest/gtest.h>

#include <visualization/language/LanguageEnglish.hpp>

class LanguageEnglishUnitTest : public testing::TestWithParam<std::tuple<model::visualization::language::Literals, std::string>>
{
    public:
        LanguageEnglishUnitTest();
        virtual ~LanguageEnglishUnitTest();

    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;

        model::visualization::language::LanguageEnglish m_englishLanguage;


};

INSTANTIATE_TEST_CASE_P(Literals, LanguageEnglishUnitTest, testing::Values(
                            std::make_tuple(model::visualization::language::Literals::FUND, "fund"),
                            std::make_tuple(model::visualization::language::Literals::DEPOSIT, "deposit"),
                            std::make_tuple(model::visualization::language::Literals::WITHDRAW, "withdraw"),
                            std::make_tuple(model::visualization::language::Literals::TRANSFER, "transfer"),
                            std::make_tuple(model::visualization::language::Literals::SUCCESS, "success"),
                            std::make_tuple(model::visualization::language::Literals::FAILURE, "failure"),
                            std::make_tuple(model::visualization::language::Literals::WARNING, "warning"),
                            std::make_tuple(model::visualization::language::Literals::SAVINGS, "savings"),
                            std::make_tuple(model::visualization::language::Literals::HOUSING, "housing")
                            ));

LanguageEnglishUnitTest::LanguageEnglishUnitTest()
{

}

LanguageEnglishUnitTest::~LanguageEnglishUnitTest()
{

}

void LanguageEnglishUnitTest::SetUp()
{
}

void LanguageEnglishUnitTest::TearDown()
{

}

TEST_P(LanguageEnglishUnitTest, literalToString)
{
    std::string expectedOutput = std::get<1>(GetParam());

    model::visualization::language::Literals literal = std::get<0>(GetParam());

    std::string output = m_englishLanguage.literalToString(literal);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiterals)
{
    std::string expectedOutput = "fund savings";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                   model::visualization::language::Literals::SAVINGS};
    std::string output = m_englishLanguage.literalToString(literals);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
    std::string expectedOutput = "fund 100 savings";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                    model::visualization::language::Literals::VALUE1,
                                                                    model::visualization::language::Literals::SAVINGS};

    std::vector<std::string> data {"100"};

    std::string output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fund 100 savings 1000";

    literals = {model::visualization::language::Literals::FUND,
                model::visualization::language::Literals::VALUE1,
                model::visualization::language::Literals::SAVINGS,
                model::visualization::language::Literals::VALUE2};

    data = {"100", "1000"};

    output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fund 100 savings 100";

    literals = {model::visualization::language::Literals::FUND,
                model::visualization::language::Literals::VALUE1,
                model::visualization::language::Literals::SAVINGS,
                model::visualization::language::Literals::VALUE1};

    data = {"100", "1000"};

    output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringError)
{
    std::string expectedOutput = "fund 100 savings";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                    model::visualization::language::Literals::VALUE1,
                                                                    model::visualization::language::Literals::SAVINGS};


    ASSERT_THROW(m_englishLanguage.literalToString(literals), std::logic_error);
}
