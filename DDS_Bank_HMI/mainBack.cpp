#include <iostream>

#include <model/source/operations/AllFunds.hpp>
#include <backend/source/controller/operations/SelectFundController.hpp>
#include <backend/source/controller/operations/DepositMoneyController.hpp>
#include <backend/source/controller/operations/WithdrawMoneyController.hpp>
#include <backend/source/controller/operations/TransferMoneyController.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>

using SelectFundController = backend::controller::operations::SelectFundController;
using DepositMoneyController = backend::controller::operations::DepositMoneyController;
using WithdrawMoneyController = backend::controller::operations::WithdrawMoneyController;
using TransferMoneyController = backend::controller::operations::TransferMoneyController;
using BackDDSView = backend::view::dds::operations::BackDDSView;

int main(int argc, char *argv[])
{
    std::shared_ptr<model::operations::AllFunds> allFunds (new model::operations::AllFunds(model::operations::FundType::SAVINGS));

    std::shared_ptr<SelectFundController> selectFundController(new SelectFundController(allFunds));
    std::shared_ptr<DepositMoneyController> depositMoneyController(new DepositMoneyController(allFunds));
    std::shared_ptr<WithdrawMoneyController> withdrawMoneyController(new WithdrawMoneyController(allFunds, allFunds, allFunds, allFunds));
    std::shared_ptr<TransferMoneyController> transferMoneyController(new TransferMoneyController(allFunds));


    std::shared_ptr<BackDDSView>backDDSView(new BackDDSView(0,2,
                                                            selectFundController,
                                                            depositMoneyController,
                                                            withdrawMoneyController,
                                                            transferMoneyController));

    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundSignal>::addSubscriber(backDDSView);
    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundTypeSignal>::addSubscriber(backDDSView);

    while(true)
    {
        int i = 0;
    }
    return 0;
}
