#include "InitializeApplication.hpp"

namespace backend
{
namespace controller
{
namespace systemConfiguration
{

InitializeApplication::InitializeApplication(std::shared_ptr<model::operations::AllFunds> allFunds) :
  mAllFunds(allFunds)
{
  downloadFunds();
}

void InitializeApplication::downloadFunds()
{
  std::string fileName = "funds.json";

  boost::property_tree::ptree rootReadNode;
  try
  {
    boost::property_tree::read_json(fileName, rootReadNode);
  }
  catch(const  boost::property_tree::json_parser_error& e)
  {
    createFundsFile(fileName);
    boost::property_tree::read_json(fileName, rootReadNode);
  }

  boost::property_tree::ptree& allFundsNode = rootReadNode.get_child("funds");

    for (const auto &fund : allFundsNode)
    {
      const std::string& nodeName = fund.first;
      const boost::property_tree::ptree& nodeData = fund.second;

      model::operations::kFundType fundType = model::operations::kFundType::_from_string(nodeName.c_str());
      int amount = nodeData.get_child("amount").get_value<int>();

      mAllFunds->setAmount(fundType, amount);
    }

}

void InitializeApplication::createFundsFile(std::string fileName)
{
  boost::property_tree::ptree rootNode;
  boost::property_tree::ptree allFundsNode;
  auto allFunds = model::operations::kFundType::_names();
  model::operations::kFundType noneFund = model::operations::kFundType::None;

  for(auto const fund : allFunds)
  {
    if(fund != noneFund._to_string())
    {
      boost::property_tree::ptree fundNode;

      fundNode.put("fundType", fund);
      fundNode.put("amount", 0);

      allFundsNode.add_child(fund, fundNode);
    }
  }
  rootNode.add_child("funds", allFundsNode);

  std::ofstream file(fileName);
  boost::property_tree::json_parser::write_json(file, rootNode);
  file.close();
}

}  // namespace systemConfiguration
}  // namespace controller
}  // namespace backend
