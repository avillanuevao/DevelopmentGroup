#include "VisualizeFundView.hpp"

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

VisualizeFundView::VisualizeFundView(QQmlApplicationEngine &engine, QObject *parent) :
    m_engine(engine),
    m_parent(parent)
{

}

void VisualizeFundView::recievedSignal(frontend::viewModel::ui::visualization::signal::VisualizeFundSignal signal)
{
    QMetaObject::invokeMethod(this, "updateAmountQML",
                                  Qt::QueuedConnection, Q_ARG(QVariant, signal.getAmount()));
}

void VisualizeFundView::updateAmountQML(const QVariant &newAmount)
{
    if(!m_engine.rootObjects().isEmpty())
    {
        QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
        QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana
        if(rootWindow)
        {
            QObject* textQML = rootObject->findChild<QObject*>("visualizeAmount", Qt::FindChildrenRecursively);
            if(textQML)
            {
                textQML->setProperty("text", newAmount);
            }else
            {
                std::cerr << "Error: Unable to find QML object with id 'displayTW'." << std::endl;
            }
        }else
        {
            std::cerr << "Error: Root object is not a QQuickWindow." << std::endl;
        }

    }else
    {
        std::cerr << "Error: No root objects found." << std::endl;
    }
}

}
}
}
}
