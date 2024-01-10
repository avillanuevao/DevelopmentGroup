#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <model/FundType.hpp>

namespace model {

    class MoneyDepositedSignal
    {
        public:
            MoneyDepositedSignal(int amount);
            //Añadir variable miembro con la cantidad para que la vista pueda acceder al valor

            int getAmount() const;
            void setAmount(int newAmount);

    private:
            int m_amount;
    };

}

#endif // SIGNAL_HPP
