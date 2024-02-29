#ifndef BACKEND_CONTROLLER_SYSTEM_CONFIGURATION_INITIALIZEAPPLICATION_HPP
#define BACKEND_CONTROLLER_SYSTEM_CONFIGURATION_INITIALIZEAPPLICATION_HPP

#include <memory>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <model/source/operations/AllFunds.hpp>
#include <model/source/operations/kFundType.hpp>

namespace backend
{
namespace controller
{
namespace systemConfiguration
{

class InitializeApplication
{
  public:
    InitializeApplication(std::shared_ptr<model::operations::AllFunds> allFunds);

  private:
    void downloadFunds();
    void createFundsFile(std::string fileName);

    std::shared_ptr<model::operations::AllFunds> mAllFunds;
};

}  // namespace systemConfiguration
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_SYSTEM_CONFIGURATION_INITIALIZEAPPLICATION_HPP
