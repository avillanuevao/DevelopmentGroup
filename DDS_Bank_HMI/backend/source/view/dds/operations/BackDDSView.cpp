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

BackDDSView::BackDDSView(unsigned int domainId,
                         unsigned int sampleCount,
                         std::shared_ptr<backend::controller::operation::SelectFundController> selectFundController,
                         std::shared_ptr<backend::controller::operation::DepositMoneyController> depositMoneyController,
                         std::shared_ptr<controller::operation::WithdrawMoneyController> withdrawMoneyController):
                         std::shared_ptr<controller::operation::TransferMoneyController> transferMoneyController):
    utils::dds::DDSView(domainId, sampleCount),
    m_selectFundController(selectFundController),
    m_depositMoneyController(depositMoneyController),
    m_withdrawMoneyController(withdrawMoneyController),
    m_transferMoneyController(transferMoneyController),
    m_readerSelectFund(m_participant, m_subscriber, SELECT_FUND_TOPIC, std::bind(&BackDDSView::receivedTopicSelectFund, this, std::placeholders::_1)),
    m_readerDeposit(m_participant, m_subscriber, DEPOSIT_TOPIC, std::bind(&BackDDSView::receivedTopicDeposit, this, std::placeholders::_1)),
    m_readerWithdraw(m_participant, m_subscriber, WITHDRAW_TOPIC, std::bind(&BackDDSView::receivedTopicWithdraw, this, std::placeholders::_1)),
    m_readerTransaction(m_participant, m_subscriber, TRANSACTION_TOPIC, std::bind(&BackDDSView::receivedTopicTransaction, this, std::placeholders::_1)),

    m_writerSelectFundAck(m_participant, m_publisher, SELECT_FUND_TOPIC_ACK),
    m_writerFundData(m_participant, m_publisher, FUND_DATA_TOPIC)

{
    utils::so::setup_signal_handlers();

    m_threadsForReading[SELECT_FUND_TOPIC] = initReadingTopicThread(&BackDDSView::readingTopicSelectFund);
    m_threadsForReading[DEPOSIT_TOPIC] = initReadingTopicThread(&BackDDSView::readingTopicDeposit);
    m_threadsForReading[WITHDRAW_TOPIC] = initReadingTopicThread(&BackDDSView::readingTopicWithdraw);
    m_threadsForReading[TRANSACTION_TOPIC] = initReadingTopicThread(&BackDDSView::readingTopicTransaction);
}

BackDDSView::~BackDDSView()
{
}

void BackDDSView::update(model::signal::UpdatedFundSignal signal)
{
    FundType ddsFundType(static_cast<FundType>(signal.getFundType()));

    writeFundData(ddsFundType, signal.getAmount());
}

void BackDDSView::update(model::signal::UpdatedFundTypeSignal signal)
{
    FundType ddsFundType(static_cast<FundType>(signal.getFundType()));

    writeSelectFundAck(ddsFundType);
}

void BackDDSView::receivedTopicSelectFund(SelectFund selectFund)
{
    std::cout << "SelectFund topic received: " << std::endl;
    std::cout << "\t" << selectFund << std::endl;

    model::FundType modelFundType (static_cast<model::FundType>(selectFund.fund_type()));
    m_selectFundController->selectFundType(modelFundType);
}

void BackDDSView::readingTopicSelectFund()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerSelectFund.wait(m_wait);
    }
}

void BackDDSView::receivedTopicDeposit(Deposit deposit)
{
    std::cout << "Deposit topic received: " << std::endl;
    std::cout << "\t" << deposit << std::endl;
    m_depositMoneyController->deposit(deposit.amount());
}

void BackDDSView::readingTopicDeposit()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerDeposit.wait(m_wait);
    }
}

void BackDDSView::receivedTopicWithdraw(Withdraw withdraw)
{
    std::cout << "Withdraw topic received: " << std::endl;
    std::cout << "\t" << withdraw << std::endl;

    try
    {

        m_withdrawMoneyController->withdraw(withdraw.amount());
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

void BackDDSView::receivedTopicTransaction(Transaction transaction)
{
    std::cout << "Transaction topic received: " << std::endl;
    std::cout << "\t" << transaction << std::endl;

    model::FundType modelFundType(static_cast<model::FundType>(transaction.fund_type_destination()));

    m_transferMoneyController->transfer(modelFundType, transaction.amount());
}

void BackDDSView::readingTopicTransaction()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerTransaction.wait(m_wait);
    }
}

void BackDDSView::writeFundData(const FundType &fundType, int16_t amount)
{
    FundData sampleFundData(fundType, amount);

    m_writerFundData.write(sampleFundData);
    std::cout << "sample FundData sended: " << std::endl
              << "\t[fundType: " << sampleFundData.fund_type() << ", amount: " << sampleFundData.amount() << "]" << std::endl;
}

void BackDDSView::writeSelectFundAck(const FundType &fundType)
{
    SelectFundAck sampleSelectFundAck(fundType);

    m_writerSelectFundAck.write(sampleSelectFundAck);
    std::cout << "sample SelectFund sended: " << std::endl
              << "\t[fundType: " << sampleSelectFundAck.fund_type() << "]" << std::endl;
}

std::thread BackDDSView::initReadingTopicThread(void (backend::view::dds::operations::BackDDSView::*function)())
{
    return std::thread(function, this);
}

}
}
}
}
