#ifndef BACKDDSVIEW_HPP
#define BACKDDSVIEW_HPP

#include <iostream>
#include <functional>
#include <thread>

#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/dds/DDSDataReader.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class BackDDSView
{
    public:
        BackDDSView(unsigned int domainId, unsigned int sampleCount);
        ~BackDDSView();

    private:
        void configureDeposit(Deposit deposit);

        unsigned int m_domainId;
        unsigned int m_sampleCount;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
//        std::shared_ptr<std::thread> m_threadDeposit;
};

}
}
}
}

#endif // BACKDDSVIEW_HPP
