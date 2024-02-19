#ifndef BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP
#define BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP

#include <model/source/operations/FundType.hpp>
#include <model/source/visualization/message/OperationType.hpp>
#include <model/source/visualization/message/AllMessagesInterface.hpp>

namespace backend
{
namespace controller
{
namespace visualization
{

class ShowMessageController
{
    public:
        ShowMessageController(std::shared_ptr<model::visualization::message::AllMessagesInterface> allMessages);

        void addMessage(std::time_t date,
                        model::visualization::message::MessageType messageType,
                        model::visualization::message::OperationType operationType,
                        int amount,
                        model::operations::FundType originFundType,
                        model::operations::FundType destinationFundType);

    private:
        std::vector<model::visualization::language::Literals> createLiterals(model::visualization::message::OperationType operationType,
                                                                             model::operations::FundType originFundType,
                                                                             model::operations::FundType destinationFundType);

        model::visualization::language::Literals toLiteral(model::operations::FundType fundType);
        model::visualization::language::Literals toLiteral(model::visualization::message::OperationType operationType);

        std::shared_ptr<model::visualization::message::AllMessagesInterface> m_allMessages;

};

}
}
}

#endif // BACKEND_CONTROLLER_VISUALIZATION_SHOWMESSAGECONTROLLER_HPP
