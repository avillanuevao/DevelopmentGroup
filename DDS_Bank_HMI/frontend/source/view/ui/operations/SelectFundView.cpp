#include "SelectFundView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

SelectFundView::SelectFundView(std::shared_ptr<frontend::viewModel::ui::operations::SelectFundViewModel> selectFundViewModel,
                               QQmlApplicationEngine &engine,
                               QObject *parent) :
    m_selectFundViewModel(selectFundViewModel),
    m_engine(engine),
    m_parent(parent)
{

}

void SelectFundView::setFundType(int fundType)
{
    m_selectFundViewModel->selectFund(static_cast<model::operations::FundType>(fundType));
}

}
}
}
}
