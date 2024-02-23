#include "Communication.hpp"

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

Communication::Communication(unsigned int domainId, unsigned int sampleCount,
       std::shared_ptr<backend::controller::operations::SelectFund> selectFundController,
       std::shared_ptr<backend::controller::operations::DepositMoney> depositMoneyController,
       std::shared_ptr<backend::controller::operations::WithdrawMoney> WithdrawMoney,
       std::shared_ptr<backend::controller::operations::TransferMoney> transferMoneyController):
  backend::view::dds::operations::CommunicationFactory(domainId, sampleCount),
  mSelectFundController(selectFundController), mDepositMoneyController(depositMoneyController),
  mWithdrawMoney(WithdrawMoney), mTransferMoneyController(transferMoneyController)
{

}

void Communication::recievedSignal(model::operations::signal::UpdatedFund signal)
{
  FundType ddsFundType(static_cast<FundType>(signal.getFundType()._to_index()));

  writeFundData(ddsFundType, signal.getAmount());
}

void Communication::recievedSignal(model::operations::signal::UpdatedFundType signal)
{
  FundType ddsFundType(static_cast<FundType>(signal.getFundType()._to_index()));

  writeSelectFundAck(ddsFundType);
}

void Communication::receivedTopicSelectFund(SelectFund selectFund)
{
  std::cout << "SelectFund topic received: " << selectFund << std::endl;

  int ddsFundType = static_cast<int>(selectFund.fund_type());
  model::operations::kFundType modelFundType(model::operations::kFundType::_from_index(ddsFundType));

  mSelectFundController->selectFundType(modelFundType);
}


void Communication::receivedTopicDeposit(Deposit deposit)
{
  std::cout << "Deposit topic received: " << deposit << std::endl;

  mDepositMoneyController->deposit(deposit.amount());
}


void Communication::receivedTopicWithdraw(Withdraw withdraw)
{
  std::cout << "Withdraw topic received: " << withdraw << std::endl;

  try
  {
    mWithdrawMoney->withdraw(withdraw.amount());
  }
  catch (std::logic_error e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void Communication::receivedTopicTransaction(Transaction transaction)
{
  std::cout << "Transaction topic received: " << transaction << std::endl;

  int ddsFundType = static_cast<int>(transaction.fund_type_destination());
  model::operations::kFundType modelFundType(model::operations::kFundType::_from_index(ddsFundType));

  mTransferMoneyController->transfer(modelFundType, transaction.amount());
}

void Communication::writeFundData(const FundType &fundType, int16_t amount)
{
  FundData sampleFundData(fundType, amount);

  mWriterFundData.write(sampleFundData);

  std::cout << "sample FundData sended: " << "[fundType: " << sampleFundData.fund_type() << ", amount: "
            << sampleFundData.amount() << "]" << std::endl;
}

void Communication::writeSelectFundAck(const FundType &fundType)
{
  SelectFundAck sampleSelectFundAck(fundType);

  mWriterSelectFundAck.write(sampleSelectFundAck);

  std::cout << "sample SelectFund sended: " << "[fundType: " << sampleSelectFundAck.fund_type() << "]"
            << std::endl;
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend
