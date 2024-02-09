#include "FrontDDSView.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

FrontDDSView::FrontDDSView(unsigned int domainId,
                           unsigned int sampleCount,
                           std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsviewModel) :
    frontend::view::dds::operations::FrontDDSViewFactory(domainId, sampleCount),
    m_ddsviewModel(ddsviewModel)
{

}

void FrontDDSView::recievedSignal(frontend::viewModel::ui::operations::signal::DepositMoneySignal signal)
{
    writeDeposit(signal.getAmount());
}

void FrontDDSView::recievedSignal(viewModel::ui::operations::signal::WithdrawnMoneySignal signal)
{
    writeWithdraw(signal.getAmount());
}

void FrontDDSView::recievedSignal(frontend::viewModel::ui::operations::signal::TransferedMoneySignal signal)
{
    writeTransaction(static_cast<FundType>(signal.getDestinationFundType()), signal.getAmount());
}

void FrontDDSView::recievedSignal(viewModel::ui::operations::signal::SelectFundSignal signal)
{
    writeSelectFund(static_cast<FundType>(signal.getFundType()));
}

void FrontDDSView::writeDeposit(int16_t amount)
{
    Deposit sampleDeposit(amount);

    m_writerDeposit.write(sampleDeposit);

    std::cout << "sample Deposit sended: " << std::endl
              << "\t[amount:" << sampleDeposit.amount() << "]" << std::endl;
}

void FrontDDSView::writeWithdraw(int16_t amount)
{
    Withdraw sampleWithdraw(amount);

    m_writerWithdraw.write(sampleWithdraw);

    std::cout << "sample Withdraw sended:  "
              << "\t[amount:" << sampleWithdraw.amount() << "]" << std::endl;
}

void FrontDDSView::writeTransaction(const FundType &destinationFundType, int16_t amount)
{
    Transaction sampleTransaction(destinationFundType, amount);

    m_writerTransfer.write(sampleTransaction);

    std::cout << "sample Transaction sended: " << std::endl
              << "\t[fundTypeDestination: " << static_cast<int>(sampleTransaction.fund_type_destination())
              << ", amount: " << sampleTransaction.amount() << "]" << std::endl;
}

void FrontDDSView::writeSelectFund(FundType fundType)
{
    SelectFund sampleSelectFund(fundType);

    m_writerSelectFund.write(sampleSelectFund);

    std::cout << "sample SelectFund sended: " << std::endl
              << "\t[" << static_cast<int>(sampleSelectFund.fund_type()) << "]" << std::endl;
}

void FrontDDSView::receivedTopicSelectFundAck(SelectFundAck selectFundAck)
{
    std::cout << "SelectFund topic recieved: " << std::endl;
    std::cout << "\t" << selectFundAck << std::endl;

    model::operations::FundType modelFundType(static_cast<model::operations::FundType>(selectFundAck.fund_type()));

    m_ddsviewModel->updateFundType(modelFundType);
}



void FrontDDSView::receivedTopicFundData(FundData fundData)
{
    std::cout << "FundData topic recieved: " << std::endl;
    std::cout << "\t" << fundData << std::endl;

    model::operations::FundType modelFundType(static_cast<model::operations::FundType>(fundData.fund_type()));

    m_ddsviewModel->updateAmount(modelFundType, fundData.amount());
}


}
}
}
}
