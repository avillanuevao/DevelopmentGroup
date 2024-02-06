#include <iostream>

#include <model/source/AllFunds.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <model/source/signal/MoneyTransferedSignal.hpp>
#include <backend/source/controller/operation/SelectFundController.hpp>
#include <backend/source/controller/operation/DepositMoneyController.hpp>
#include <backend/source/controller/operation/WithdrawMoneyController.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>

using SelectFundController = backend::controller::operation::SelectFundController;
using DepositMoneyController = backend::controller::operation::DepositMoneyController;
using WithdrawMoneyController = backend::controller::operation::WithdrawMoneyController;
using BackDDSView = backend::view::dds::operations::BackDDSView;

int main(int argc, char *argv[])
{
    std::shared_ptr<model::AllFunds> allFunds (new model::AllFunds(model::FundType::SAVINGS));

    std::shared_ptr<SelectFundController> selectFundController(new SelectFundController(allFunds));
    std::shared_ptr<DepositMoneyController> depositMoneyController(new DepositMoneyController(allFunds));
    std::shared_ptr<WithdrawMoneyController> withdrawMoneyController(new WithdrawMoneyController(allFunds, allFunds, allFunds, allFunds));


    std::shared_ptr<BackDDSView>backDDSView(new BackDDSView(0,2,
                                                            selectFundController,
                                                            depositMoneyController,
                                                            withdrawMoneyController));

    allFunds->utils::designPattern::SignalPublisher<model::signal::UpdatedFundSignal>::addSubscriber(backDDSView);
    allFunds->utils::designPattern::SignalPublisher<model::signal::UpdatedFundTypeSignal>::addSubscriber(backDDSView);

    while(true)
    {
        int i = 0;
    }
    return 0;
}
