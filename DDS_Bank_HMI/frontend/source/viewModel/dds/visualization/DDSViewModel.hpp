#ifndef FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/visualization/message/aAllMessages.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

class DDSViewModel
{
  public:
    DDSViewModel(std::shared_ptr<model::visualization::message::aAllMessages> allMessage);

    void addMessage(model::visualization::message::aMessage message);

  private:
    std::shared_ptr<model::visualization::message::aAllMessages> mAllMessage;
};

}  // namespace visualization
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend

#endif // FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP
