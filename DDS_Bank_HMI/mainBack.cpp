#include <iostream>

#include <model/source/AllFunds.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <model/source/signal/MoneyTransferedSignal.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>

using BackDDSView = backend::view::dds::operations::BackDDSView;

int main(int argc, char *argv[])
{
    std::shared_ptr<model::AllFunds> allFunds (new model::AllFunds(model::FundType::SAVINGS));
    std::shared_ptr<BackDDSView>backDDSView(new BackDDSView(allFunds, 0,2));

    allFunds->addSubscriber(backDDSView);

    while(true)
    {
        int i = 0;
    }
    return 0;
}
