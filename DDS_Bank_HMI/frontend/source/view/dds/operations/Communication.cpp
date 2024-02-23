#include "Communication.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

Communication::Communication(unsigned int domainId, unsigned int sampleCount,
                             std::shared_ptr<frontend::viewModel::dds::operations::Communication> ddsviewModel) :
  frontend::view::dds::operations::CommunicationFactory(domainId, sampleCount), mDDSviewModel(ddsviewModel)
{

}

void Communication::recievedSignal(frontend::viewModel::ui::operations::signal::DepositMoney signal)
{
  writeDeposit(signal.getAmount());
}

void Communication::recievedSignal(viewModel::ui::operations::signal::SelectFund signal)
{
  FundType ddsFundType = static_cast<FundType>(signal.getFundType()._to_index());
  writeSelectFund(ddsFundType);
}

void Communication::recievedSignal(frontend::viewModel::ui::operations::signal::TransferedMoney signal)
{
  FundType ddsFundType = static_cast<FundType>(signal.getDestinationFundType()._to_index());
  writeTransaction(ddsFundType, signal.getAmount());
}

void Communication::recievedSignal(viewModel::ui::operations::signal::WithdrawnMoney signal)
{
  writeWithdraw(signal.getAmount());
}

void Communication::receivedTopicFundData(FundData fundData)
{
  std::cout << "FundData topic recieved: " << fundData << std::endl;

  int ddsFundType = static_cast<int>(fundData.fund_type());
  model::operations::kFundType modelFundType = model::operations::kFundType::_from_index(ddsFundType);

  mDDSviewModel->updateAmount(modelFundType, fundData.amount());
}

void Communication::receivedTopicSelectFundAck(SelectFundAck selectFundAck)
{
  std::cout << "SelectFund topic recieved: " << "\t" << selectFundAck << std::endl;

  int ddsFundType = static_cast<int>(selectFundAck.fund_type());
  model::operations::kFundType modelFundType = model::operations::kFundType::_from_index(ddsFundType);

  mDDSviewModel->updateFundType(modelFundType);
}

void Communication::writeDeposit(int16_t amount)
{
  Deposit sampleDeposit(amount);

  mWriterDeposit.write(sampleDeposit);

  std::cout << "sample Deposit sended: " << "\t[amount:" << sampleDeposit.amount() << "]" << std::endl;
}

void Communication::writeSelectFund(FundType fundType)
{
  SelectFund sampleSelectFund(fundType);

  mWriterSelectFund.write(sampleSelectFund);

  std::cout << "sample SelectFund sended: " << "\t[" << static_cast<int>(sampleSelectFund.fund_type())
            << "]" << std::endl;
}

void Communication::writeTransaction(const FundType &destinationFundType, int16_t amount)
{
  Transaction sampleTransaction(destinationFundType, amount);

  mWriterTransfer.write(sampleTransaction);

  std::cout << "sample Transaction sended: " <<  "\t[fundTypeDestination: "
            << static_cast<int>(sampleTransaction.fund_type_destination()) << ", amount: "
            << sampleTransaction.amount() << "]" << std::endl;
}

void Communication::writeWithdraw(int16_t amount)
{
  Withdraw sampleWithdraw(amount);

  mWriterWithdraw.write(sampleWithdraw);

  std::cout << "sample Withdraw sended:  " << "\t[amount:" << sampleWithdraw.amount() << "]" << std::endl;
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace frontend
