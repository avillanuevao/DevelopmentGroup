#include "SelectFundView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

SelectFundView::SelectFundView(std::shared_ptr<frontend::viewModel::ui::operations::SelectFund> selectFundViewModel,
                               QQmlApplicationEngine &engine,
                               QObject *parent) :
    m_selectFundViewModel(selectFundViewModel),
    m_engine(engine),
    m_parent(parent)
{

}

void SelectFundView::setFundType(QString fundType)
{
    try
    {
        model::operations::kFundType modelFundType = model::operations::kFundType::_from_string_nocase(fundType.toStdString().c_str());
        m_selectFundViewModel->selectFund(modelFundType);
    }  catch (std::runtime_error e)
    {
        e.what();
    }

}

}
}
}
}
