#include "ShowMessageView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

ShowMessageView::ShowMessageView(std::shared_ptr<model::visualization::language::aLanguage> languages,
                                 QQmlApplicationEngine &engine,
                                 QObject *parent):
    m_language(languages),
    m_engine(engine),
    m_parent(parent)
{

}

void ShowMessageView::recievedSignal(viewModel::ui::visualization::signal::ShowMessage signal)
{
    model::visualization::message::aMessage messageInterface = signal.getMessage();

    QVariant message = QString::fromStdString(composeMessage(messageInterface));
    QVariant color = colorMessage(messageInterface.getMessageType());

    QMetaObject::invokeMethod(this,
                              "showMessageQML",
                              Qt::QueuedConnection,
                              Q_ARG(QVariant, message), Q_ARG(QVariant, color));
}

void ShowMessageView::showMessageQML(const QVariant& message, const QVariant& color)
{
    if(!m_engine.rootObjects().isEmpty())
    {
        QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
        QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana
        if(rootWindow)
        {
            QObject* popupQML = rootObject->findChild<QObject*>("popupMessage", Qt::FindChildrenRecursively);
            if(popupQML)
            {
                popupQML->setProperty("visible", true);
                popupQML->setProperty("text", message);
                popupQML->setProperty("color", color);
            }
            else
            {
                std::cerr << "Error: Unable to find QML object with id 'popupMessage'." << std::endl;
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

QColor ShowMessageView::colorMessage(model::visualization::message::kMessageType messageType)
{
    switch (messageType)
    {
        case model::visualization::message::kMessageType::Success:
            return MESSAGE_SUCCESS;
            break;
        case model::visualization::message::kMessageType::Failure:
            return MESSAGE_FAILURE;
            break;
        case model::visualization::message::kMessageType::Warning:
            return MESSAGE_WARNING;
            break;
    }
}

std::string ShowMessageView::composeMessage(model::visualization::message::aMessage messageInterface)
{
    std::string message;

    message += formatDate(messageInterface.getDate()) + " - ";
    message += formatMessageType(messageInterface.getMessageType()) + " - ";
    message += m_language->literalToString(messageInterface.getLiterals(), messageInterface.getData());

    return message;
}

std::string ShowMessageView::formatMessageType(model::visualization::message::kMessageType messageType)
{
    switch (messageType)
    {
        case model::visualization::message::kMessageType::Success:
            return m_language->literalToString(model::visualization::language::kLiterals::Success);
            break;
        case model::visualization::message::kMessageType::Failure:
            return m_language->literalToString(model::visualization::language::kLiterals::Failure);
            break;
        case model::visualization::message::kMessageType::Warning:
            return m_language->literalToString(model::visualization::language::kLiterals::Warning);
            break;
    }
}

std::string ShowMessageView::formatDate(time_t date)
{
    std::tm* timeInfo = std::localtime(&date);
    char buffer[80];

    std::strftime(buffer, 80, "%H:%M %d/%m/%Y", timeInfo);

    return std::string(buffer);
}



}
}
}
}

