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
                          std::make_tuple(model::visualization::language::kLiterals::Fund, "fondo"),
                          std::make_tuple(model::visualization::language::kLiterals::Deposit, "depósito"),
                          std::make_tuple(model::visualization::language::kLiterals::Withdraw, "extracción"),
                          std::make_tuple(model::visualization::language::kLiterals::Transfer, "transferencia"),
                          std::make_tuple(model::visualization::language::kLiterals::Success, "éxito"),
                          std::make_tuple(model::visualization::language::kLiterals::Failure, "fallo"),
                          std::make_tuple(model::visualization::language::kLiterals::Warning, "advertencia"),
                          std::make_tuple(model::visualization::language::kLiterals::Savings, "ahorro"),
                          std::make_tuple(model::visualization::language::kLiterals::Housing, "hogar")
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

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Savings};
  std::string output = m_spanishLanguage.literalToString(literals);

  ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
  std::string expectedOutput = "fondo 100 ahorro";

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Value1,
    model::visualization::language::kLiterals::Savings};

  std::vector<std::string> data {"100"};

  std::string output = m_spanishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);

  expectedOutput = "fondo 100 ahorro 1000";

  literals = {model::visualization::language::kLiterals::Fund,
              model::visualization::language::kLiterals::Value1,
              model::visualization::language::kLiterals::Savings,
              model::visualization::language::kLiterals::Value2};

  data = {"100", "1000"};

  output = m_spanishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);

  expectedOutput = "fondo 100 ahorro 100";

  literals = {model::visualization::language::kLiterals::Fund,
              model::visualization::language::kLiterals::Value1,
              model::visualization::language::kLiterals::Savings,
              model::visualization::language::kLiterals::Value1};

  data = {"100", "1000"};

  output = m_spanishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageSpanishUnitTest, literalToStringError)
{
  std::string expectedOutput = "fondo 100 ahorro";

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Value1,
    model::visualization::language::kLiterals::Savings};

  ASSERT_THROW(m_spanishLanguage.literalToString(literals), std::logic_error);
}
