#include "ShowMessageView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

ShowMessageView::ShowMessageView(std::shared_ptr<model::visualization::language::AllLanguagesInterface> allLanguages,
                                 QQmlApplicationEngine &engine,
                                 QObject *parent):
    m_allLanguages(allLanguages),
    m_engine(engine),
    m_parent(parent)
{

}

void ShowMessageView::recievedSignal(viewModel::ui::visualization::signal::ShowMessageSignal signal)
{
    // Formar el string en el idioma que sea y llamar a showMessageQML
    // toString(MessageInterface message)
    // colorString(MessageType messageType)
}

void ShowMessageView::showMessageQML(const QVariant& message, const QVariant& color)
{

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

//    message = m_allLanguages->getActualLanguage()->literalToString(...);
//    message = m_language->literalToString(...)->
}



}
}
}
}

