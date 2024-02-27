#ifndef FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP

#include <iostream>
#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/visualization/signal/UpdatedLanguage.hpp>
#include <model/source/visualization/language/aLanguage.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

class Visualize :
    public QObject,
    public utils::designPattern::SignalSubscriber<
    frontend::viewModel::ui::visualization::signal::UpdatedLanguage>
{
    Q_OBJECT
  public:
    Visualize(const std::shared_ptr<model::visualization::language::aLanguage> language,
              QQmlApplicationEngine& engine, QObject* parent = nullptr);

    ~Visualize() override;

    void recievedSignal(frontend::viewModel::ui::visualization::signal::UpdatedLanguage signal) override;

  private slots:
    void updateQML(QVariant objectName, QVariant property, QVariant propertyValue);
    void refreshQMLContent();

  private:
    struct ObjectQML
    {
        QString id;
        QString property;
        model::visualization::language::kLiterals literal;
    };

    struct ComboBoxQML
    {
        QString id;
        QString property;
        std::list<model::visualization::language::kLiterals> model;
    };

    void initObjectsQML();
    void initComboBoxQML();
    void initFundsAvailables();
    void initLanguagesAvailables();
    QVariantList toQVariantList(std::list<model::visualization::language::kLiterals> literals);


    const std::shared_ptr<model::visualization::language::aLanguage> mLanguage;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    std::list<ObjectQML> mObjectsQML;
    std::list<ComboBoxQML> mComboBoxQML;
    std::list<model::visualization::language::kLiterals> mFundsAvailables;
    std::list<model::visualization::language::kLiterals> mLanguageAvailables;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP
