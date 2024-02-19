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

void ShowMessageView::recievedSignal(viewModel::ui::visualization::signal::ShowMessageSignal signal)
{
    model::visualization::message::MessageInterface messageInterface = signal.getMessage();

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

QColor ShowMessageView::colorMessage(model::visualization::message::MessageType messageType)
{
    switch (messageType)
    {
        case model::visualization::message::MessageType::SUCCESS:
            return MESSAGE_SUCCESS;
            break;
        case model::visualization::message::MessageType::FAILURE:
            return MESSAGE_FAILURE;
            break;
        case model::visualization::message::MessageType::WARNING:
            return MESSAGE_WARNING;
            break;
    }
}

std::string ShowMessageView::composeMessage(model::visualization::message::MessageInterface messageInterface)
{
    std::string message;

    message += formatDate(messageInterface.getDate()) + " - ";
    message += formatMessageType(messageInterface.getMessageType()) + " - ";
    message += m_language->literalToString(messageInterface.getLiterals(), messageInterface.getData());

    return message;
}

std::string ShowMessageView::formatMessageType(model::visualization::message::MessageType messageType)
{
    switch (messageType)
    {
        case model::visualization::message::MessageType::SUCCESS:
            return m_language->literalToString(model::visualization::language::kLiterals::kSuccess);
            break;
        case model::visualization::message::MessageType::FAILURE:
            return m_language->literalToString(model::visualization::language::kLiterals::kFailure);
            break;
        case model::visualization::message::MessageType::WARNING:
            return m_language->literalToString(model::visualization::language::kLiterals::kWarning);
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

