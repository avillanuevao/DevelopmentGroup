#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUNDSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUNDSIGNAL_HPP

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

class VisualizeFundSignal
{
    public:
        VisualizeFundSignal(int amount);

        int getAmount() const;
        void setAmount(int newAmount);

private:
        int m_amount;
};

}
}
}
}
}


#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_VISUALIZEFUNDSIGNAL_HPP
