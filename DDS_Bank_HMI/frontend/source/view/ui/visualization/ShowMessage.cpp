#include "ShowMessage.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

ShowMessage::ShowMessage(std::shared_ptr<model::visualization::language::aLanguage> languages,
                                 QQmlApplicationEngine& engine, QObject* parent) :
  mLanguage(languages), mEngine(engine), mParent(parent)
{

}

void ShowMessage::recievedSignal(viewModel::ui::visualization::signal::ShowMessage signal)
{
  model::visualization::message::aMessage messageInterface = signal.getMessage();

  QVariant message = QString::fromStdString(composeMessage(messageInterface));
  QVariant color = colorMessage(messageInterface.getMessageType());

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, message),
                            Q_ARG(QVariant, color));
}

void ShowMessage::showMessageQML(const QVariant& message, const QVariant& color)
{
  if(!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
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

QColor ShowMessage::colorMessage(model::visualization::message::kMessageType messageType)
{
  switch (messageType)
  {
    case model::visualization::message::kMessageType::Success:
      return kMessageSuccess;
      break;
    case model::visualization::message::kMessageType::Failure:
      return kMessageFailure;
      break;
    case model::visualization::message::kMessageType::Warning:
      return kMessageWarning;
      break;
  }
}

std::string ShowMessage::composeMessage(model::visualization::message::aMessage messageInterface)
{
  std::string message;

  message += formatDate(messageInterface.getDate()) + " - ";
  message += formatMessageType(messageInterface.getMessageType()) + " - ";
  message += mLanguage->literalToString(messageInterface.getLiterals(), messageInterface.getData());

  return message;
}

std::string ShowMessage::formatMessageType(model::visualization::message::kMessageType messageType)
{
  switch (messageType)
  {
    case model::visualization::message::kMessageType::Success:
      return mLanguage->literalToString(model::visualization::language::kLiterals::Success);
      break;
    case model::visualization::message::kMessageType::Failure:
      return mLanguage->literalToString(model::visualization::language::kLiterals::Failure);
      break;
    case model::visualization::message::kMessageType::Warning:
      return mLanguage->literalToString(model::visualization::language::kLiterals::Warning);
      break;
  }
}

std::string ShowMessage::formatDate(time_t date)
{
  std::tm* timeInfo = std::localtime(&date);
  char buffer[80];

  std::strftime(buffer, 80, "%H:%M %d/%m/%Y", timeInfo);

  return std::string(buffer);
}

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend
