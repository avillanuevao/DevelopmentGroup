#include "FrontDDSView.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

FrontDDSView::FrontDDSView(unsigned int domainId, unsigned int sampleCount,
                           std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsviewModel) :
  frontend::view::dds::operations::FrontDDSViewFactory(domainId, sampleCount), mDDSviewModel(ddsviewModel)
{

}

void FrontDDSView::recievedSignal(frontend::viewModel::ui::operations::signal::DepositMoney signal)
{
  writeDeposit(signal.getAmount());
}

void FrontDDSView::recievedSignal(viewModel::ui::operations::signal::SelectFund signal)
{
  FundType ddsFundType = static_cast<FundType>(signal.getFundType()._to_index());
  writeSelectFund(ddsFundType);
}

void FrontDDSView::recievedSignal(frontend::viewModel::ui::operations::signal::TransferedMoney signal)
{
  FundType ddsFundType = static_cast<FundType>(signal.getDestinationFundType()._to_index());
  writeTransaction(ddsFundType, signal.getAmount());
}

void FrontDDSView::recievedSignal(viewModel::ui::operations::signal::WithdrawnMoney signal)
{
  writeWithdraw(signal.getAmount());
}

void FrontDDSView::receivedTopicFundData(FundData fundData)
{
  std::cout << "FundData topic recieved: " << std::endl;
  std::cout << "\t" << fundData << std::endl;

  int ddsFundType = static_cast<int>(fundData.fund_type());
  model::operations::kFundType modelFundType = model::operations::kFundType::_from_index(ddsFundType);

  mDDSviewModel->updateAmount(modelFundType, fundData.amount());
}

void FrontDDSView::receivedTopicSelectFundAck(SelectFundAck selectFundAck)
{
  std::cout << "SelectFund topic recieved: " << "\t" << selectFundAck << std::endl;

  int ddsFundType = static_cast<int>(selectFundAck.fund_type());
  model::operations::kFundType modelFundType = model::operations::kFundType::_from_index(ddsFundType);

  mDDSviewModel->updateFundType(modelFundType);
}

void FrontDDSView::writeDeposit(int16_t amount)
{
  Deposit sampleDeposit(amount);

  mWriterDeposit.write(sampleDeposit);

  std::cout << "sample Deposit sended: " << "\t[amount:" << sampleDeposit.amount() << "]" << std::endl;
}

void FrontDDSView::writeSelectFund(FundType fundType)
{
  SelectFund sampleSelectFund(fundType);

  mWriterSelectFund.write(sampleSelectFund);

  std::cout << "sample SelectFund sended: " << "\t[" << static_cast<int>(sampleSelectFund.fund_type())
            << "]" << std::endl;
}

void FrontDDSView::writeTransaction(const FundType &destinationFundType, int16_t amount)
{
  Transaction sampleTransaction(destinationFundType, amount);

  mWriterTransfer.write(sampleTransaction);

  std::cout << "sample Transaction sended: " <<  "\t[fundTypeDestination: "
            << static_cast<int>(sampleTransaction.fund_type_destination()) << ", amount: "
            << sampleTransaction.amount() << "]" << std::endl;
}

void FrontDDSView::writeWithdraw(int16_t amount)
{
  Withdraw sampleWithdraw(amount);

  mWriterWithdraw.write(sampleWithdraw);

  std::cout << "sample Withdraw sended:  " << "\t[amount:" << sampleWithdraw.amount() << "]" << std::endl;
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace frontend
