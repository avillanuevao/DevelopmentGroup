#include "VisualizeFund.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{
namespace signal
{

VisualizeFund::VisualizeFund(int amount) :
  mAmount(amount)
{

}

int VisualizeFund::getAmount() const
{
  return mAmount;
}

void VisualizeFund::setAmount(int newAmount)
{
  mAmount = newAmount;
}

}  // namespace signal
}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
