#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP

#include <model/source/operations/FundType.hpp>

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
        SelectFundSignal(model::operations::FundType fundType);

        model::operations::FundType getFundType() const;
        void setFundType(model::operations::FundType newFundType);

private:
        model::operations::FundType m_fundType;
};

}
}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
