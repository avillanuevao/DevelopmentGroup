#ifndef FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP

#include <vector>
#include <memory>
#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>

#include <frontend/source/viewModel/ui/visualization/SelectLanguage.hpp>
#include <model/source/visualization/language/kLanguagesAvailables.hpp>

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
    void setLanguage(int language);

  private:
    std::shared_ptr<frontend::viewModel::ui::visualization::SelectLanguage> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    std::vector<model::visualization::language::kLanguagesAvailables> mOrderLanguages;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
