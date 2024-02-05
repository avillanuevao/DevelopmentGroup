#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <memory>

#include <model/source/FundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class DepositViewModel:
        public utils::designPattern::SignalPublisher<viewModel::signal::DepositMoneySignal>
{
    public:
        DepositViewModel();
        void depositMoney(int amount);
};

}
}
}
}
#endif // DEPOSITVIEWMODEL_HPP
