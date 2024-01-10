#ifndef DEPOSITMONEYSIGNAL_HPP
#define DEPOSITMONEYSIGNAL_HPP

#include <idl/bank.hpp>

namespace viewModel {
    namespace signal {
        class DepositMoneySignal
        {
            public:
                DepositMoneySignal(FundType fundType,  int amount);

                FundType getFundType() const;
                int getAmount() const;

        private:
                FundType m_fundType;
                int m_amount;

        };
    }
}

#endif // DEPOSITMONEYSIGNAL_HPP
