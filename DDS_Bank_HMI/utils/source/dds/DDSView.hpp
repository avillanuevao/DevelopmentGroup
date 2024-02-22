#ifndef UTILS_DDS_DDSVIEW_HPP
#define UTILS_DDS_DDSVIEW_HPP

#include <thread>

#include <dds/pub/Publisher.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

#include <dds/DDSDataReader.hpp>
#include <dds/DDSDataWriter.hpp>
#include <so/Shutdown.hpp>

namespace utils
{
namespace dds
{

class DDSView
{
  public:
    DDSView(unsigned int domainId, unsigned int sampleCount);

  protected:
    template<class TTopic>
    utils::dds::DDSDataReader<TTopic> createDataReader(const std::string& topicName,
                                                       std::function<void(TTopic)> function)
    {
      return utils::dds::DDSDataReader<TTopic>(mParticipant, mSubscriber, topicName, function);
    }

    template<class TTopic>
    utils::dds::DDSDataWriter<TTopic> createrDataWriter(const std::string& topicName)
    {
      return utils::dds::DDSDataWriter<TTopic>(mParticipant, mPublisher, topicName);
    }

    unsigned int mDomainId;
    unsigned int mSampleCount;
    ::dds::core::Duration mWait;
    std::shared_ptr<::dds::domain::DomainParticipant> mParticipant;
    std::shared_ptr<::dds::pub::Publisher> mPublisher;
    std::shared_ptr<::dds::sub::Subscriber> mSubscriber;
    std::map<std::string, std::thread> mThreadsForReading;
};

}  // namespace dds
}  // namespace utils


#endif  // UTILS_DDS_DDSVIEW_HPP
