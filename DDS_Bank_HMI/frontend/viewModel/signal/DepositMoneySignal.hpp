#ifndef DEPOSITMONEYSIGNAL_HPP
#define DEPOSITMONEYSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class DepositMoneySignal
{
    public:
        DepositMoneySignal(model::FundType fundType,  int amount);

        model::FundType getFundType() const;
        int getAmount() const;

    private:
        model::FundType m_fundType;
        int m_amount;

};

}
}
}
#endif // DEPOSITMONEYSIGNAL_HPP
