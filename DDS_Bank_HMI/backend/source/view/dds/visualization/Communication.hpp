#ifndef BACKEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP
#define BACKEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP

#include <idl/bank.hpp>
#include <model/source/visualization/message/signal/ShowMessage.hpp>
#include <utils/source/dds/DDSView.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace visualization
{

class Communication :
    public utils::dds::DDSView,
    public utils::designPattern::SignalSubscriber<model::visualization::message::signal::ShowMessage>
{
  public:
    Communication(unsigned int domainId, unsigned int sampleCount);

    void recievedSignal(model::visualization::message::signal::ShowMessage signal) override;

  private:
    void writeMessage(Message sampleMessage);
    std::vector<int> toIntVector(std::vector<model::visualization::language::kLiterals> literals);
    Message toMessageTopic(model::visualization::message::signal::ShowMessage signal);

    utils::dds::DDSDataWriter<Message> mWriterMessage;
};

}  // namespace visualization
}  // namespace dds
}  // namespace view
}  // namespace backend

#endif  // BACKEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP
