#include <gtest/gtest.h>

#include <visualization/language/LanguageEnglish.hpp>

class LanguageEnglishUnitTest :
    public testing::TestWithParam<std::tuple<model::visualization::language::kLiterals, std::string>>
{
  public:
    LanguageEnglishUnitTest();
    virtual ~LanguageEnglishUnitTest();

  protected:
    virtual void SetUp() override;
    virtual void TearDown() override;

    model::visualization::language::LanguageEnglish mEnglishLanguage;
};

INSTANTIATE_TEST_CASE_P(Literals, LanguageEnglishUnitTest, testing::Values(
                          std::make_tuple(model::visualization::language::kLiterals::Fund, "fund"),
                          std::make_tuple(model::visualization::language::kLiterals::Deposit, "deposit"),
                          std::make_tuple(model::visualization::language::kLiterals::Withdraw, "withdraw"),
                          std::make_tuple(model::visualization::language::kLiterals::Transfer, "transfer"),
                          std::make_tuple(model::visualization::language::kLiterals::Success, "success"),
                          std::make_tuple(model::visualization::language::kLiterals::Failure, "failure"),
                          std::make_tuple(model::visualization::language::kLiterals::Warning, "warning"),
                          std::make_tuple(model::visualization::language::kLiterals::Savings, "savings"),
                          std::make_tuple(model::visualization::language::kLiterals::Housing, "housing")
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

  std::string output = mEnglishLanguage.literalToString(literal);

  ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiterals)
{
  std::string expectedOutput = "fund savings";

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Savings};
  std::string output = mEnglishLanguage.literalToString(literals);

  ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringVectorLiteralsAndVectorData)
{
  std::string expectedOutput = "fund 100 savings";

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Value1,
    model::visualization::language::kLiterals::Savings};

  std::vector<std::string> data {"100"};

  std::string output = mEnglishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);

  expectedOutput = "fund 100 savings 1000";

  literals = {model::visualization::language::kLiterals::Fund,
              model::visualization::language::kLiterals::Value1,
              model::visualization::language::kLiterals::Savings,
              model::visualization::language::kLiterals::Value2};

  data = {"100", "1000"};

  output = mEnglishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);

  expectedOutput = "fund 100 savings 100";

  literals = {model::visualization::language::kLiterals::Fund,
              model::visualization::language::kLiterals::Value1,
              model::visualization::language::kLiterals::Savings,
              model::visualization::language::kLiterals::Value1};

  data = {"100", "1000"};

  output = mEnglishLanguage.literalToString(literals, data);

  ASSERT_EQ(expectedOutput, output);
}

TEST_F(LanguageEnglishUnitTest, literalToStringError)
{
  std::string expectedOutput = "fund 100 savings";

  std::vector<model::visualization::language::kLiterals> literals {
    model::visualization::language::kLiterals::Fund, model::visualization::language::kLiterals::Value1,
    model::visualization::language::kLiterals::Savings};

  ASSERT_THROW(mEnglishLanguage.literalToString(literals), std::logic_error);
}
