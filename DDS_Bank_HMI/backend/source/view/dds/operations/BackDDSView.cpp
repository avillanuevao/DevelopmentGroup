#include "BackDDSView.hpp"

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

BackDDSView::BackDDSView(unsigned int domainId, unsigned int sampleCount,
       std::shared_ptr<backend::controller::operations::SelectFund> selectFundController,
       std::shared_ptr<backend::controller::operations::DepositMoney> depositMoneyController,
       std::shared_ptr<backend::controller::operations::WithdrawMoney> WithdrawMoney,
       std::shared_ptr<backend::controller::operations::TransferMoney> transferMoneyController):
  backend::view::dds::operations::BackDDSViewFactory(domainId, sampleCount),
  m_selectFundController(selectFundController),
  m_depositMoneyController(depositMoneyController),
  m_WithdrawMoney(WithdrawMoney),
  m_transferMoneyController(transferMoneyController)
{

}

void BackDDSView::recievedSignal(model::operations::signal::UpdatedFund signal)
{
  FundType ddsFundType(static_cast<FundType>(signal.getFundType()._to_index()));

  writeFundData(ddsFundType, signal.getAmount());
}

void BackDDSView::recievedSignal(model::operations::signal::UpdatedFundType signal)
{
  FundType ddsFundType(static_cast<FundType>(signal.getFundType()._to_index()));

  writeSelectFundAck(ddsFundType);
}

void BackDDSView::receivedTopicSelectFund(SelectFund selectFund)
{
  std::cout << "SelectFund topic received: " << std::endl;
  std::cout << "\t" << selectFund << std::endl;

  int ddsFundType = static_cast<int>(selectFund.fund_type());
  model::operations::kFundType modelFundType(model::operations::kFundType::_from_index(ddsFundType));

  m_selectFundController->selectFundType(modelFundType);
}


void BackDDSView::receivedTopicDeposit(Deposit deposit)
{
  std::cout << "Deposit topic received: " << std::endl;
  std::cout << "\t" << deposit << std::endl;

  m_depositMoneyController->deposit(deposit.amount());
}


void BackDDSView::receivedTopicWithdraw(Withdraw withdraw)
{
  std::cout << "Withdraw topic received: " << std::endl;
  std::cout << "\t" << withdraw << std::endl;

  try
  {

    m_WithdrawMoney->withdraw(withdraw.amount());
  }
  catch (std::logic_error e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void BackDDSView::receivedTopicTransaction(Transaction transaction)
{
  std::cout << "Transaction topic received: " << std::endl;
  std::cout << "\t" << transaction << std::endl;

  int ddsFundType = static_cast<int>(transaction.fund_type_destination());
  model::operations::kFundType modelFundType(model::operations::kFundType::_from_index(ddsFundType));

  m_transferMoneyController->transfer(modelFundType, transaction.amount());
}

void BackDDSView::writeFundData(const FundType &fundType, int16_t amount)
{
  FundData sampleFundData(fundType, amount);

  mWriterFundData.write(sampleFundData);

  std::cout << "sample FundData sended: " << std::endl
            << "\t[fundType: " << sampleFundData.fund_type() << ", amount: " << sampleFundData.amount()
            << "]" << std::endl;
}

void BackDDSView::writeSelectFundAck(const FundType &fundType)
{
  SelectFundAck sampleSelectFundAck(fundType);

  mWriterSelectFundAck.write(sampleSelectFundAck);

  std::cout << "sample SelectFund sended: " << std::endl
            << "\t[fundType: " << sampleSelectFundAck.fund_type() << "]" << std::endl;
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend
