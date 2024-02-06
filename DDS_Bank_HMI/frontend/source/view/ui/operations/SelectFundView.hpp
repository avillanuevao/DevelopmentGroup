#ifndef FRONTEND_VIEW_UI_OPERATIONS_SELECTFUNDVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_SELECTFUNDVIEW_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>

#include <model/source/FundType.hpp>
#include <frontend/source/viewModel/ui/operations/SelectFundViewModel.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class SelectFundView :
        public QObject
{
    Q_OBJECT

    public:
        SelectFundView(std::shared_ptr<frontend::viewModel::ui::operations::SelectFundViewModel> selectFundViewModel,
                       QQmlApplicationEngine &engine,
                       QObject *parent = nullptr);

    public slots:
        void setFundType(int fundType);

    private:
        std::shared_ptr<frontend::viewModel::ui::operations::SelectFundViewModel> m_selectFundViewModel;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
};

}
}
}
}


#endif // FRONTEND_VIEW_UI_OPERATIONS_SELECTFUNDVIEW_HPP
