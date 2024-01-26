#include "TransferMoneyController.hpp"

namespace  backend
{
namespace  controller
{
namespace  operation
{

TransferMoneyController::TransferMoneyController(std::shared_ptr<model::AllFunds> allFunds) :
    m_allFunds(allFunds)
{

}

void TransferMoneyController::doTransaction(model::Operation transaction)
{

}

}
}
}
