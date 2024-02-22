#ifndef BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP
#define BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP

#include <model/source/operations/kFundType.hpp>
#include <model/source/visualization/message/kOperationType.hpp>
#include <model/source/visualization/message/aAllMessages.hpp>

namespace backend
{
namespace controller
{
namespace visualization
{

class ShowMessageController
{
    public:
        ShowMessageController(std::shared_ptr<model::visualization::message::aAllMessages> allMessages);

        void addMessage(std::time_t date,
                        model::visualization::message::kMessageType messageType,
                        model::visualization::message::kOperationType operationType,
                        int amount,
                        model::operations::kFundType originFundType,
                        model::operations::kFundType destinationFundType);

    private:
        std::vector<model::visualization::language::kLiterals> createLiterals(model::visualization::message::kOperationType operationType,
                                                                             model::operations::kFundType originFundType,
                                                                             model::operations::kFundType destinationFundType);

        model::visualization::language::kLiterals toLiteral(model::operations::kFundType fundType);
        model::visualization::language::kLiterals toLiteral(model::visualization::message::kOperationType operationType);

        std::shared_ptr<model::visualization::message::aAllMessages> m_allMessages;

};

}
}
}

#endif // BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP
