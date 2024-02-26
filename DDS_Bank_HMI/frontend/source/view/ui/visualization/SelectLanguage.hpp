#ifndef FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP

#include <QObject>
#include <QQmlApplicationEngine>

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
    SelectLanguage(QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void setLanguage(QString language);

  private:
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_SELECTLANGUAGE_HPP
