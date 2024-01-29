#include <iostream>

#include <model/source/AllFunds.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>

using BackDDSView = backend::view::dds::operations::BackDDSView;

int main(int argc, char *argv[])
{
    std::shared_ptr<model::AllFunds> allFunds = std::make_shared<model::AllFunds>();
    std::shared_ptr<BackDDSView>backDDSView(new BackDDSView(allFunds, 0,2));

    allFunds->utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::addSubscriber(backDDSView);
    allFunds->utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::addSubscriber(backDDSView);

    // To keep runing the backend
    while(true)
    {
        int i = 0;
    }
    return 0;
}
