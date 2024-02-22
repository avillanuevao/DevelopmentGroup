#ifndef BACKEND_VIEW_DDS_VISUALIZATION_BACKDDSVIEW_HPP
#define BACKEND_VIEW_DDS_VISUALIZATION_BACKDDSVIEW_HPP

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

class BackDDSView :
        public utils::dds::DDSView,
        public utils::designPattern::SignalSubscriber<model::visualization::message::signal::ShowMessage>
{
    public:
        BackDDSView(unsigned int domainId,
                    unsigned int sampleCount);

        void recievedSignal(model::visualization::message::signal::ShowMessage signal);

    private:
        void writeMessage(Message sampleMessage);
        std::vector<int> toIntVector(std::vector<model::visualization::language::kLiterals> literals);
        Message toMessageTopic(model::visualization::message::signal::ShowMessage signal);

        utils::dds::DDSDataWriter<Message> m_writerMessage;


};

}
}
}
}


#endif // BACKEND_VIEW_DDS_VISUALIZATION_BACKDDSVIEW_HPP
