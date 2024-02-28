#include "Visualize.hpp"

using kLiterals = model::visualization::language::kLiterals;

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

Visualize::Visualize(const std::shared_ptr<model::visualization::language::aLanguage> language,
                     QQmlApplicationEngine& engine, QObject* parent) :
  mLanguage(language), mEngine(engine), mParent(parent)
{
  initFundsAvailables();
  initLanguagesAvailables();
  initObjectsQML();
  initComboBoxQML();
}

Visualize::~Visualize()
{

}

void Visualize::recievedSignal(viewModel::ui::visualization::signal::UpdatedLanguage signal)
{

  refreshQMLContent();
}

void Visualize::updateObjectQML(QVariant objectName, QVariant property, QVariant propertyValue)
{
  if(!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if(rootWindow)
    {
      QObject* objectQML = rootObject->findChild<QObject*>(objectName.toString(), Qt::FindChildrenRecursively);
      if(objectQML)
      {
        objectQML->setProperty(property.toString().toStdString().c_str(), propertyValue);
      }
      else
      {
        std::cerr << "Error: Unable to find QML object with id '" << objectName.toString().toStdString() <<"'." <<
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

void Visualize::updateComboBoxQML(QVariant objectName, QVariant property, QVariantList propertyValue)
{
  if(!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if(rootWindow)
    {
      QObject* objectQML = rootObject->findChild<QObject*>(objectName.toString(), Qt::FindChildrenRecursively);
      if(objectQML)
      {
        objectQML->setProperty(property.toString().toStdString().c_str(), propertyValue);
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

void Visualize::initObjectsQML()
{
  mObjectsQML.push_back(ObjectQML{"depositRB", "text", kLiterals::Deposit});

  mObjectsQML.push_back(ObjectQML{"withdrawRB", "text", kLiterals::Withdraw});

  mObjectsQML.push_back(ObjectQML{"transferRB", "text", kLiterals::Transfer});

  mObjectsQML.push_back(ObjectQML{"deposit", "textButton", kLiterals::Accept});

  mObjectsQML.push_back(ObjectQML{"deposit", "placeholderText", kLiterals::AmountDeposit});

  mObjectsQML.push_back(ObjectQML{"withdraw", "textButton", kLiterals::Accept});

  mObjectsQML.push_back(ObjectQML{"withdraw", "placeholderText", kLiterals::AmountWithdraw});

  mObjectsQML.push_back(ObjectQML{"transfer", "textButton", kLiterals::Accept});

  mObjectsQML.push_back(ObjectQML{"transfer", "placeholderText", kLiterals::AmountTransfer});

  mObjectsQML.push_back(ObjectQML{"transfer", "textDestination", kLiterals::DestinationTransfer});
}

void Visualize::initComboBoxQML()
{
  mComboBoxQML.push_back(ComboBoxQML{"transfer", "modelFund", mFundsAvailables});

  mComboBoxQML.push_back(ComboBoxQML{"selectFund", "modelFund", mFundsAvailables});

  mComboBoxQML.push_back(ComboBoxQML{"selectLanguage", "modelLanguage", mLanguageAvailables});
}

void Visualize::initFundsAvailables()
{
  mFundsAvailables.push_back(kLiterals::Savings);
  mFundsAvailables.push_back(kLiterals::Housing);
}

void Visualize::initLanguagesAvailables()
{
  mLanguageAvailables.push_back(kLiterals::English);
  mLanguageAvailables.push_back(kLiterals::Spanish);
}

QVariantList Visualize::toQVariantList(std::list<model::visualization::language::kLiterals> literals)
{
  QVariantList elements;

  for(const kLiterals literal : literals)
  {
    QString sLiteral = QString::fromStdString(mLanguage->literalToString(literal));

    elements.append(sLiteral);
  }

  return elements;
}

void Visualize::refreshQMLContent()
{
  for(const ObjectQML& object : mObjectsQML)
  {
    // TODO: New name to sLiteral
    QString sLiteral = QString::fromStdString(mLanguage->literalToString(object.literal));

    QMetaObject::invokeMethod(this, "updateObjectQML", Qt::QueuedConnection, Q_ARG(QVariant, object.id),
                              Q_ARG(QVariant, object.property), Q_ARG(QVariant, sLiteral));
  }

  for(const ComboBoxQML& comboBox : mComboBoxQML)
  {
    QMetaObject::invokeMethod(this, "updateComboBoxQML", Qt::QueuedConnection, Q_ARG(QVariant, comboBox.id),
                              Q_ARG(QVariant, comboBox.property),
                              Q_ARG(QVariantList, toQVariantList(comboBox.model)));
  }
}

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend
