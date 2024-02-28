#ifndef BACKEND_VIEW_INCLUDEVIEW_OPERATIONS_SAVEFUND_HPP
#define BACKEND_VIEW_INCLUDEVIEW_OPERATIONS_SAVEFUND_HPP

#include <memory>

#include <controller/operations/SaveFund.hpp>
#include <controller/operations/signal/SaveFund.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace backend
{
namespace view
{
namespace includeView
{
namespace operations
{

class SaveFund :
    public utils::designPattern::SignalSubscriber<backend::controller::operations::signal::SaveFund>
{
  public:
    SaveFund(std::shared_ptr<backend::controller::operations::SaveFund> saveFundController);

    void recievedSignal(backend::controller::operations::signal::SaveFund signal) override;

  private:
    std::shared_ptr<backend::controller::operations::SaveFund> mController;
};

}  // namespace operations
}  // namespace includeView
}  // namespace view
}  // namespace backend

#endif // BACKEND_VIEW_INCLUDEVIEW_OPERATIONS_SAVEFUND_HPP
