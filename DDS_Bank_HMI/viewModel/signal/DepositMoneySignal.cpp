#include "DepositMoneySignal.hpp"

namespace viewModel {
    namespace signal {
        DepositMoneySignal::DepositMoneySignal(FundType fundType,  int amount):
            m_fundType(fundType),
            m_amount(amount)
        {

        }

        FundType DepositMoneySignal::getFundType() const
        {
            return m_fundType;
        }

        int DepositMoneySignal::getAmount() const
        {
            return m_amount;
        }

    }
}
