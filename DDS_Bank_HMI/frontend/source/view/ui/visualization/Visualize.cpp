#include "Visualize.hpp"

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

Visualize::Visualize(QQmlApplicationEngine& engine, QObject* parent) :
  mEngine(engine), mParent(parent)
{

}

void Visualize::recievedSignal(viewModel::ui::visualization::signal::UpdatedLanguage signal)
{
  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "depositRB"),
                            Q_ARG(QVariant, "text"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Deposit))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "withdrawRB"),
                            Q_ARG(QVariant, "text"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Withdraw))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "transferRB"),
                            Q_ARG(QVariant, "text"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Transfer))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "deposit"),
                            Q_ARG(QVariant, "textButton"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Accept))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "deposit"),
                            Q_ARG(QVariant, "placeholderText"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::AmountDeposit))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "withdraw"),
                            Q_ARG(QVariant, "textButton"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Accept))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "withdraw"),
                            Q_ARG(QVariant, "placeholderText"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::AmountWithdraw))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "transfer"),
                            Q_ARG(QVariant, "textButton"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::Transfer))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "transfer"),
                            Q_ARG(QVariant, "textDestination"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::DestinationTransfer))));

  QMetaObject::invokeMethod(this, "showMessageQML", Qt::QueuedConnection, Q_ARG(QVariant, "transfer"),
                            Q_ARG(QVariant, "placeholderText"), Q_ARG(QVariant,
                                  QString::fromStdString(mLanguage->literalToString(
                                                           model::visualization::language::kLiterals::AmountTransfer))));
  //TODO:     property alias modelFund: fundTypeDestinationTransferComboBox.model
}

void Visualize::showMessageQML(QString objectName, QString property, QString propertyValue)
{
  if(!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if(rootWindow)
    {
      QObject* objectQML = rootObject->findChild<QObject*>(objectName, Qt::FindChildrenRecursively);
      if(objectQML)
      {
        objectQML->setProperty(property.toStdString().c_str(), propertyValue);
      }
      else
      {
        std::cerr << "Error: Unable to find QML object with id '" << objectName.toStdString() <<"'." <<
                     std::endl;
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
