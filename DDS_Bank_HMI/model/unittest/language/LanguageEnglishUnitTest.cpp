#include <gtest/gtest.h>

#include <visualization/language/LanguageEnglish.hpp>

class LanguageEnglishUnitTest : public testing::TestWithParam<std::tuple<model::visualization::language::kLiterals, std::string>>
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
                            std::make_tuple(model::visualization::language::kLiterals::kFund, "fund"),
                            std::make_tuple(model::visualization::language::kLiterals::kDeposit, "deposit"),
                            std::make_tuple(model::visualization::language::kLiterals::kWithdraw, "withdraw"),
                            std::make_tuple(model::visualization::language::kLiterals::kTransfer, "transfer"),
                            std::make_tuple(model::visualization::language::kLiterals::kSuccess, "success"),
                            std::make_tuple(model::visualization::language::kLiterals::kFailure, "failure"),
                            std::make_tuple(model::visualization::language::kLiterals::kWarning, "warning"),
                            std::make_tuple(model::visualization::language::kLiterals::kSavings, "savings"),
                            std::make_tuple(model::visualization::language::kLiterals::kHousing, "housing")
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

    model::visualization::language::kLiterals literal = std::get<0>(GetParam());

    std::string output = m_englishLanguage.literalToString(literal);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiterals)
{
    std::string expectedOutput = "fund savings";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                   model::visualization::language::kLiterals::kSavings};
    std::string output = m_englishLanguage.literalToString(literals);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
    std::string expectedOutput = "fund 100 savings";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                    model::visualization::language::kLiterals::kValue1,
                                                                    model::visualization::language::kLiterals::kSavings};

    std::vector<std::string> data {"100"};

    std::string output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fund 100 savings 1000";

    literals = {model::visualization::language::kLiterals::kFund,
                model::visualization::language::kLiterals::kValue1,
                model::visualization::language::kLiterals::kSavings,
                model::visualization::language::kLiterals::kValue2};

    data = {"100", "1000"};

    output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fund 100 savings 100";

    literals = {model::visualization::language::kLiterals::kFund,
                model::visualization::language::kLiterals::kValue1,
                model::visualization::language::kLiterals::kSavings,
                model::visualization::language::kLiterals::kValue1};

    data = {"100", "1000"};

    output = m_englishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringError)
{
    std::string expectedOutput = "fund 100 savings";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                    model::visualization::language::kLiterals::kValue1,
                                                                    model::visualization::language::kLiterals::kSavings};


    ASSERT_THROW(m_englishLanguage.literalToString(literals), std::logic_error);
}
