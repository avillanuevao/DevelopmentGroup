#ifndef UTILS_DDS_DDSDATAREADER_HPP
#define UTILS_DDS_DDSDATAREADER_HPP

#include <memory>

#include <dds/core/ddscore.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/config/Logger.hpp>

namespace utils
{
namespace dds
{

template <class TTopic>
class DDSDataReader
{
  public:
    DDSDataReader(std::shared_ptr<::dds::domain::DomainParticipant> participant,
                  std::shared_ptr<::dds::sub::Subscriber> subscriber, const std::string& topicName,
                  std::function<void(TTopic)> function):
      mParticipant(participant), mSubscriber(subscriber), mTopicName(topicName),
      mFunctionRecieveTopic(function), mTopic(*mParticipant, mTopicName), mReader(*mSubscriber, mTopic),
      mStatusCondition(mReader)

    {
      mStatusCondition.enabled_statuses(::dds::core::status::StatusMask::data_available());
      mStatusCondition.extensions().handler(std::bind(&DDSDataReader::getSample, this));
    }

    void wait(::dds::core::Duration seconds)
    {
      ::dds::core::cond::WaitSet waitset;
      waitset += mStatusCondition;
      waitset.dispatch(seconds);
    }

  private:
    void getSample()
    {
      ::dds::sub::LoanedSamples<TTopic> samples = mReader->take();
      for(auto sample : samples)
      {
        if(sample.info().valid())
        {
          mFunctionRecieveTopic(sample.data());
        }
      }
    }

    std::shared_ptr<::dds::domain::DomainParticipant> mParticipant;
    std::shared_ptr<::dds::sub::Subscriber> mSubscriber;
    const std::string& mTopicName;
    std::function<void(TTopic)> mFunctionRecieveTopic;
    ::dds::topic::Topic<TTopic> mTopic;
    ::dds::sub::DataReader<TTopic> mReader;
    ::dds::core::cond::StatusCondition mStatusCondition;
};

}  // namespace dds
}  // namespace utils

#endif  // UTILS_DDS_DDSDATAREADER_HPP
