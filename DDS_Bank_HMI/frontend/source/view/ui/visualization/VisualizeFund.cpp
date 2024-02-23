#include "VisualizeFund.hpp"

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

VisualizeFund::VisualizeFund(QQmlApplicationEngine &engine, QObject *parent) :
  mengine(engine), mParent(parent)
{

}

void VisualizeFund::recievedSignal(frontend::viewModel::ui::visualization::signal::VisualizeFund signal)
{
  QMetaObject::invokeMethod(this, "updateAmountQML", Qt::QueuedConnection,
                            Q_ARG(QVariant, signal.getAmount()));
}

void VisualizeFund::updateAmountQML(const QVariant &newAmount)
{
  if(!mengine.rootObjects().isEmpty())
  {
    QObject* rootObject = mengine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
      QObject* textQML = rootObject->findChild<QObject*>("visualizeAmount", Qt::FindChildrenRecursively);
      if(textQML)
      {
        textQML->setProperty("text", newAmount);
      }
      else
      {
        std::cerr << "Error: Unable to find QML object with id 'visualizeAmount'." << std::endl;
      }
    }
    else
    {
      std::cerr << "Error: Root object is not a QQuickWindow." << std::endl;
    }

  }
  else
  {
    std::cerr << "Error: No root objects found." << std::endl;
  }
}

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend
