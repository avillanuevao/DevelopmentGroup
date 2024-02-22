#include "WithdrawnMoney.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

WithdrawnMoney::WithdrawnMoney(int amount) :
    mAmount(amount)
{

}

int WithdrawnMoney::getAmount() const
{
    return mAmount;
}

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
