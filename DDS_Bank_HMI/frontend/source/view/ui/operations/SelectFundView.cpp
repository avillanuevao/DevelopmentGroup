#include "SelectFundView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

SelectFundView::SelectFundView(std::shared_ptr<viewModel::ui::operations::SelectFundViewModel> selectFundViewModel) :
    m_selectFundViewModel(selectFundViewModel)
{

}

void SelectFundView::setFundType(int fundType)
{
    m_selectFundViewModel->selectFund(static_cast<model::FundType>(fundType));
}

}
}
}
}
