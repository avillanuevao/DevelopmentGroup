#ifndef MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP

#include <chrono>
#include <memory>
#include <vector>

#include <visualization/message/MessageType.hpp>
#include <visualization/language/kLiterals.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class MessageInterface
{
    public:
        MessageInterface(const model::visualization::message::MessageInterface& message);
        MessageInterface(std::time_t date,
                         model::visualization::message::MessageType messageType,
                         std::vector<model::visualization::language::kLiterals> literals,
                         std::vector<std::string> data);

        virtual std::time_t getDate() const;
        virtual const model::visualization::message::MessageType &getMessageType() const;
        virtual const std::vector<model::visualization::language::kLiterals> &getLiterals() const;

        virtual const std::vector<std::string> &getData() const;

    protected:
        std::time_t m_date;
        model::visualization::message::MessageType m_messageType;
        std::vector<model::visualization::language::kLiterals> m_literals;
        std::vector<std::string> m_data;

};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP
