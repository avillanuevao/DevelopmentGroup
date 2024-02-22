#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOABSTRACTADAPTER_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOABSTRACTADAPTER_HPP

#include <idl/bank.hpp>
#include <model/source/visualization/message/aMessage.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

class MessageDDStoAbstractAdapter :
    public model::visualization::message::aMessage
{
  public:
    MessageDDStoAbstractAdapter(Message message);

  private:
    std::vector<model::visualization::language::kLiterals> toLiterals(std::vector<int> iLiterals);
    model::visualization::message::aMessage createMessage(Message message);
};

}  // namespace visualization
}  // namespace dds
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOABSTRACTADAPTER_HPP
