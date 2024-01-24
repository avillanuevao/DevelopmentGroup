#include <iostream>

#include <model/source/AllFunds.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>

int main(int argc, char *argv[])
{
    std::shared_ptr<model::AllFunds> allFunds = std::make_shared<model::AllFunds>();
    std::shared_ptr<backend::view::dds::operations::BackDDSView>
            backDDSView(new backend::view::dds::operations::BackDDSView(allFunds, 0,2));

    allFunds->addSubscriber(backDDSView);
    //allFunds->notifySubscribers(model::signal::MoneyDepositedSignal(FundType::HOUSING, 10));
    while(true)
    {
        int i = 0;
    }
    return 0;
}
