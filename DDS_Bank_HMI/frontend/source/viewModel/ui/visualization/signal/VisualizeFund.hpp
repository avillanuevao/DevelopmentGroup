#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUND_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUND_HPP

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

class VisualizeFund
{
  public:
    VisualizeFund(int amount);

    int getAmount() const;
    void setAmount(int newAmount);

  private:
    int mAmount;
};

}  // namespace signal
}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUND_HPP
