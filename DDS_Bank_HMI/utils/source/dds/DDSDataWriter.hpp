#ifndef UTILS_DDS_DDSDATAWRITER_HPP
#define UTILS_DDS_DDSDATAWRITER_HPP

#include <memory>

#include <dds/pub/ddspub.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

namespace utils
{
namespace dds
{

template <class TTopic>
class DDSDataWriter
{
  public:
    DDSDataWriter(std::shared_ptr<::dds::domain::DomainParticipant> participant,
                  std::shared_ptr<::dds::pub::Publisher> publisher,
                  const std::string& topicName):
      mParticipant(participant), mPublisher(publisher), mTopicName(topicName), mTopic(*mParticipant, mTopicName),
      mDataWriter(*mPublisher, mTopic)
    {

    }

    void write(TTopic sample)
    {
      mDataWriter.write(sample);
    }

  private:
    std::shared_ptr<::dds::domain::DomainParticipant> mParticipant;
    std::shared_ptr<::dds::pub::Publisher> mPublisher;
    const std::string& mTopicName;
    ::dds::topic::Topic<TTopic> mTopic;
    ::dds::pub::DataWriter<TTopic> mDataWriter;
};

}  // namespace dds
}  // namespace utils

#endif  // UTILS_DDS_DDSDATAWRITER_HPP
