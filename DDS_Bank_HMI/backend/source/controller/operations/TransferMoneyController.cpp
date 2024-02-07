#include "TransferMoneyController.hpp"

namespace  backend
{
namespace  controller
{
namespace  operations
{

TransferMoneyController::TransferMoneyController(std::shared_ptr<model::operations::FundTransferAmountInterface> fund):
    m_fund(fund)
{

}

void TransferMoneyController::transfer(model::operations::FundType destinationFundType, int amount)
{
    try {
        m_fund->transferAmount(destinationFundType, amount);
    }  catch (std::logic_error e) {
        std::cerr << e.what() << std::endl;
    }
}

}
}
}
