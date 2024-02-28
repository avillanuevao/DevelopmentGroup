#include "SaveFund.hpp"

namespace backend
{
namespace controller
{
namespace operations
{

SaveFund::SaveFund(std::shared_ptr<model::operations::iFundGetAmountByFundType> fund) :
  mFund(fund)
{

}

void SaveFund::saveFund(model::operations::kFundType fundChanged)
{
  std::string fileName = "funds.json";

  boost::property_tree::ptree rootReadNode;
  boost::property_tree::read_json(fileName, rootReadNode);

  boost::property_tree::ptree& allFundsNode = rootReadNode.get_child("funds");
  boost::property_tree::ptree& fundNode = allFundsNode.get_child(fundChanged._to_string());
  fundNode.put("amount", mFund->getAmount(fundChanged));

  std::ofstream file(fileName);
  boost::property_tree::json_parser::write_json(file, rootReadNode);
  file.flush();
  file.close();
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
