#include "BackDDSView.hpp"
#include <utils/source/so/Shutdown.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

BackDDSView::BackDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domainId, unsigned int sampleCount):
    m_allFunds(allFunds),
    m_domainId(domainId),
    m_sampleCount(sampleCount),
    m_depositMoneyController(new backend::controller::operation::DepositMoneyController(m_allFunds)),
    //m_withdrawMoneyController(new backend::controller::operation::WithdrawMoneyController(m_allFunds)),
    //m_transferMoneyController(new backend::controller::operation::TransferMoneyController(m_allFunds)),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(m_domainId)),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant)),
    m_readerDeposit(m_participant, m_subscriber, DEPOSIT_TOPIC, std::bind(&BackDDSView::configureDeposit, this, std::placeholders::_1)),
    m_readerWithdraw(m_participant, m_subscriber, WITHDRAW_TOPIC, std::bind(&BackDDSView::receivedTopicWithdraw, this, std::placeholders::_1)),
    m_readerTransaction(m_participant, m_subscriber, TRANSACTION_TOPIC, std::bind(&BackDDSView::configureTransaction, this, std::placeholders::_1)),
    m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
    m_writerFundData(m_participant, m_publisher, FUND_DATA_TOPIC)

{
    utils::so::setup_signal_handlers();
    m_wait = ::dds::core::Duration(1);
    m_threadDeposit = std::make_shared<std::thread>(&BackDDSView::initDepositUseCase, this);
    m_threadTransaction = std::make_shared<std::thread>(&BackDDSView::initTransactionUseCase, this);
    m_threadWithdraw = std::make_shared<std::thread>(&BackDDSView::readingTopicWithdraw, this);
}

BackDDSView::~BackDDSView()
{
    deleteThread(m_threadDeposit);
    deleteThread(m_threadWithdraw);
    deleteThread(m_threadTransaction);
}

void BackDDSView::update(model::signal::UpdatedFundSignal signal)
{
    writeFundData(static_cast<FundType>(signal.getFundType()), signal.getAmount());
}

void BackDDSView::configureDeposit(Deposit deposit)
{
    std::cout << "Deposit topic received: " << std::endl;
    std::cout << "\t" << deposit << std::endl;
    m_depositMoneyController->deposit(deposit.amount());
}

void BackDDSView::initDepositUseCase()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerDeposit.wait(m_wait);
    }
}

void BackDDSView::configureTransaction(Transaction transaction)
{
    std::cout << "Data obtenido transaccion: " << std::endl;
    std::cout << "\t" << transaction << std::endl;

//    m_transferMoneyController->doTransaction(model::Operation(
//                static_cast<model::FundType>(transaction.fund_type_origin()),
//                static_cast<model::FundType>(transaction.fund_type_destination()), transaction.amount()));
}

void BackDDSView::initTransactionUseCase()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerTransaction.wait(m_wait);
    }
}

const FundData BackDDSView::writeFundData(const FundType &fundType, int16_t amount)
{
    FundData sampleFundData(fundType, amount);

    m_writerFundData.write(sampleFundData);
    std::cout << "topic sended: " << std::endl
              << "\t[fundType: " << sampleFundData.fund_type() << ", amount: " << sampleFundData.amount() << "]" << std::endl;

    return sampleFundData;
}

void BackDDSView::receivedTopicWithdraw(Withdraw withdraw)
{
    std::cout << "Withdraw topic received: " << std::endl;
    std::cout << "\t" << withdraw << std::endl;

    try{

//        m_withdrawMoneyController->withdraw(model::Operation(model::FundType::NONE,
//                                                             static_cast<model::FundType>(withdraw.fund_type()),
//                                                             withdraw.amount()));
    }
    catch (std::logic_error e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void BackDDSView::readingTopicWithdraw()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerWithdraw.wait(m_wait);
    }
}

void BackDDSView::deleteThread(std::shared_ptr<std::thread> thread)
{
    thread->join();
    thread.reset();
    thread = nullptr;
}

}
}
}
}
