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
        DepositMoneySignal(int amount);

        int getAmount() const;

    private:
        int m_amount;

};

}
}
}
#endif // DEPOSITMONEYSIGNAL_HPP
