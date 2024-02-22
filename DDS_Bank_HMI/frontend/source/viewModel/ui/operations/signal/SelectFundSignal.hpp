#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP

#include <model/source/operations/kFundType.hpp>

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
        SelectFundSignal(model::operations::kFundType fundType);

        model::operations::kFundType getFundType() const;
        void setFundType(model::operations::kFundType newFundType);

private:
        model::operations::kFundType m_fundType;
};

}
}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUNDSIGNAL_HPP
