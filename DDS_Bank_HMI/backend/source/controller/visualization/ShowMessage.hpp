#ifndef BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGE_HPP
#define BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGE_HPP

#include <model/source/operations/kFundType.hpp>
#include <model/source/visualization/language/EnumToLiteral.hpp>
#include <model/source/visualization/message/aAllMessages.hpp>
#include <model/source/visualization/message/kOperationType.hpp>

namespace backend
{
namespace controller
{
namespace visualization
{

class ShowMessage
{
  public:
    ShowMessage(std::shared_ptr<model::visualization::message::aAllMessages> allMessages);

    void addMessage(std::time_t date, model::visualization::message::kMessageType messageType,
                    model::visualization::message::kOperationType operationType, int amount,
                    model::operations::kFundType originFundType,
                    model::operations::kFundType destinationFundType);

  private:
    std::vector<model::visualization::language::kLiterals> createLiterals(
        model::visualization::message::kOperationType operationType,
        model::operations::kFundType originFundType, model::operations::kFundType destinationFundType);
    model::visualization::language::kLiterals toLiteral(model::operations::kFundType fundType);
    model::visualization::language::kLiterals toLiteral(model::visualization::message::kOperationType operationType);

    std::shared_ptr<model::visualization::message::aAllMessages> m_allMessages;
};

}  // namespace visualization
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGE_HPP
