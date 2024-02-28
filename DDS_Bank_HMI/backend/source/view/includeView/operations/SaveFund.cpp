#include "SaveFund.hpp"

namespace backend
{
namespace view
{
namespace includeView
{
namespace operations
{

SaveFund::SaveFund(std::shared_ptr<controller::operations::SaveFund> saveFundController) :
  mController(saveFundController)
{

}

void SaveFund::recievedSignal(controller::operations::signal::SaveFund signal)
{
  mController->saveFund(signal.getFundChanged());
}

}  // namespace operations
}  // namespace includeView
}  // namespace view
}  // namespace backend
