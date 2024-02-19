#include <gtest/gtest.h>

#include <visualization/language/LanguageSpanish.hpp>

class LanguageSpanishUnitTest :
        public testing::TestWithParam<std::tuple<model::visualization::language::Literals, std::string>>
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
                            std::make_tuple(model::visualization::language::Literals::FUND, "fondo"),
                            std::make_tuple(model::visualization::language::Literals::DEPOSIT, "depósito"),
                            std::make_tuple(model::visualization::language::Literals::WITHDRAW, "extracción"),
                            std::make_tuple(model::visualization::language::Literals::TRANSFER, "transferencia"),
                            std::make_tuple(model::visualization::language::Literals::SUCCESS, "éxito"),
                            std::make_tuple(model::visualization::language::Literals::FAILURE, "fallo"),
                            std::make_tuple(model::visualization::language::Literals::WARNING, "advertencia"),
                            std::make_tuple(model::visualization::language::Literals::SAVINGS, "ahorro"),
                            std::make_tuple(model::visualization::language::Literals::HOUSING, "hogar")
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

    model::visualization::language::Literals literal = std::get<0>(GetParam());

    std::string output = m_spanishLanguage.literalToString(literal);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringVectorLiterals)
{
    std::string expectedOutput = "fondo ahorro";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                   model::visualization::language::Literals::SAVINGS};
    std::string output = m_spanishLanguage.literalToString(literals);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
    std::string expectedOutput = "fondo 100 ahorro";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                    model::visualization::language::Literals::VALUE1,
                                                                    model::visualization::language::Literals::SAVINGS};

    std::vector<std::string> data {"100"};

    std::string output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fondo 100 ahorro 1000";

    literals = {model::visualization::language::Literals::FUND,
                model::visualization::language::Literals::VALUE1,
                model::visualization::language::Literals::SAVINGS,
                model::visualization::language::Literals::VALUE2};

    data = {"100", "1000"};

    output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);

    expectedOutput = "fondo 100 ahorro 100";

    literals = {model::visualization::language::Literals::FUND,
                model::visualization::language::Literals::VALUE1,
                model::visualization::language::Literals::SAVINGS,
                model::visualization::language::Literals::VALUE1};

    data = {"100", "1000"};

    output = m_spanishLanguage.literalToString(literals, data);

    ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringError)
{
    std::string expectedOutput = "fondo 100 ahorro";

    std::vector<model::visualization::language::Literals> literals {model::visualization::language::Literals::FUND,
                                                                    model::visualization::language::Literals::VALUE1,
                                                                    model::visualization::language::Literals::SAVINGS};


    ASSERT_THROW(m_spanishLanguage.literalToString(literals), std::logic_error);
}
