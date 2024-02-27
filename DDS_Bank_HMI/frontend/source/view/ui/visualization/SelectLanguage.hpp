#ifndef FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>

#include <frontend/source/viewModel/ui/visualization/SelectLanguage.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

class SelectLanguage :
    public QObject
{
    Q_OBJECT

  public:
    SelectLanguage(std::shared_ptr<frontend::viewModel::ui::visualization::SelectLanguage> viewModel,
                   QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void setLanguage(QString language);

  private:
    std::shared_ptr<frontend::viewModel::ui::visualization::SelectLanguage> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
