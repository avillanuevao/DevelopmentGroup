#include <gtest/gtest.h>

#include <visualization/language/LanguageSpanish.hpp>

class LanguageSpanishUnitTest :
        public testing::TestWithParam<std::tuple<model::visualization::language::kLiterals, std::string>>
{
    public:
        LanguageSpanishUnitTest();
        virtual ~LanguageSpanishUnitTest();

    protected:
        virtual void SetUp() override;
        virtual void TearDown() override;

        model::visualization::language::LanguageSpanish m_spanishLanguage;

};

INSTANTIATE_TEST_CASE_P(Literals, LanguageSpanishUnitTest, testing::Values(
                            std::make_tuple(model::visualization::language::kLiterals::kFund, "fondo"),
                            std::make_tuple(model::visualization::language::kLiterals::kDeposit, "depósito"),
                            std::make_tuple(model::visualization::language::kLiterals::kWithdraw, "extracción"),
                            std::make_tuple(model::visualization::language::kLiterals::kTransfer, "transferencia"),
                            std::make_tuple(model::visualization::language::kLiterals::kSuccess, "éxito"),
                            std::make_tuple(model::visualization::language::kLiterals::kFailure, "fallo"),
                            std::make_tuple(model::visualization::language::kLiterals::kWarning, "advertencia"),
                            std::make_tuple(model::visualization::language::kLiterals::kSavings, "ahorro"),
                            std::make_tuple(model::visualization::language::kLiterals::kHousing, "hogar")
                            ));

LanguageSpanishUnitTest::LanguageSpanishUnitTest()
{

}

LanguageSpanishUnitTest::~LanguageSpanishUnitTest()
{

}

void LanguageSpanishUnitTest::SetUp()
{

}

void LanguageSpanishUnitTest::TearDown()
{

}

TEST_P(LanguageSpanishUnitTest, literalToString)
{
    std::string expectedOutput = std::get<1>(GetParam());

    model::visualization::language::kLiterals literal = std::get<0>(GetParam());

    std::string output = m_spanishLanguage.literalToString(literal);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringVectorLiterals)
{
    std::string expectedOutput = "fondo ahorro";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                   model::visualization::language::kLiterals::kSavings};
    std::string output = m_spanishLanguage.literalToString(literals);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
    std::string expectedOutput = "fondo 100 ahorro";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                    model::visualization::language::kLiterals::kValue1,
                                                                    model::visualization::language::kLiterals::kSavings};

    std::vector<std::string> data {"100"};

    std::string output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fondo 100 ahorro 1000";

    literals = {model::visualization::language::kLiterals::kFund,
                model::visualization::language::kLiterals::kValue1,
                model::visualization::language::kLiterals::kSavings,
                model::visualization::language::kLiterals::kValue2};

    data = {"100", "1000"};

    output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fondo 100 ahorro 100";

    literals = {model::visualization::language::kLiterals::kFund,
                model::visualization::language::kLiterals::kValue1,
                model::visualization::language::kLiterals::kSavings,
                model::visualization::language::kLiterals::kValue1};

    data = {"100", "1000"};

    output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringError)
{
    std::string expectedOutput = "fondo 100 ahorro";

    std::vector<model::visualization::language::kLiterals> literals {model::visualization::language::kLiterals::kFund,
                                                                    model::visualization::language::kLiterals::kValue1,
                                                                    model::visualization::language::kLiterals::kSavings};


    ASSERT_THROW(m_spanishLanguage.literalToString(literals), std::logic_error);
}
