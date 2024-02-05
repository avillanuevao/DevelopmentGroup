#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP

#include <model/source/FundType.hpp>

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


class SelectFundSignal
{
    public:
        SelectFundSignal(model::FundType fundType);

        model::FundType getFundType() const;
        void setFundType(model::FundType newFundType);

private:
        model::FundType m_fundType;
};

}
}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
