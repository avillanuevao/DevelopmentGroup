#include "Communication.hpp"

namespace backend
{
namespace view
{
namespace dds
{
namespace visualization
{

Communication::Communication(unsigned int domainId, unsigned int sampleCount) :
  utils::dds::DDSView(domainId, sampleCount), mWriterMessage(createrDataWriter<Message>(MESSAGE_TOPIC))
{

}

void Communication::recievedSignal(model::visualization::message::signal::ShowMessage signal)
{
  Message sampleMessage = toMessageTopic(signal);

  writeMessage(sampleMessage);
}

void Communication::writeMessage(Message sampleMessage)
{
  mWriterMessage.write(sampleMessage);
  std::cout << "sample Message sended:" << "[date: " << sampleMessage.date() << ", " << "messageType: "
            << sampleMessage.message_type() << ", " << "literals: " << sampleMessage.literals() << ", "
            << "data: " << sampleMessage.data() << "]" << std::endl;
}

std::vector<int> Communication::toIntVector(std::vector<model::visualization::language::kLiterals> literals)
{
  std::vector<int> iLiterals(literals.size());

  for(size_t index = 0; index < literals.size(); index++)
  {
    iLiterals[index] = literals[index];
  }

  return iLiterals;
}

Message Communication::toMessageTopic(model::visualization::message::signal::ShowMessage signal)
{
  model::visualization::message::aMessage message = signal.getMessage();
  std::vector<model::visualization::language::kLiterals> literals = message.getLiterals();
  std::vector<std::string> data = message.getData();

  int64_t ddsDate (static_cast<int64_t>(message.getDate()));
  MessageType ddsMessageType = static_cast<MessageType>(message.getMessageType()._to_index());
  ::rti::core::bounded_sequence< std::string, 100L > ddsData(data);
  ::rti::core::bounded_sequence<int32_t, 100L> ddsLiterals(toIntVector(literals));

  Message sampleMessage(ddsDate, ddsMessageType, ddsLiterals, ddsData);

  return sampleMessage;
}

}  // namespace visualization
}  // namespace dds
}  // namespace view
}  // namespace backend
