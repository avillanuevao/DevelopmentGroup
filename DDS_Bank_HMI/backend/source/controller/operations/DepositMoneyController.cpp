#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operations
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::operations::FundIncreaseAmountInterface> fund) :
    m_fund(fund)
{

}

void DepositMoneyController::deposit(int amount)
{
    try {
        m_fund->increaseAmount(amount);
    }  catch (std::logic_error e) {
        //TODO: Si es negativo mandarselo a traves de showMessage (UC)
        std::cerr << e.what() << std::endl;
    }
//    std::numeric_limits<int>::max(); #include <limits>
}

}
}
}

