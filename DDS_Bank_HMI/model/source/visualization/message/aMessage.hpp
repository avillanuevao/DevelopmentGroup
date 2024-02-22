#ifndef MODEL_VISUALIZATION_MESSAGE_AMESSAGE_HPP
#define MODEL_VISUALIZATION_MESSAGE_AMESSAGE_HPP

#include <chrono>
#include <memory>
#include <vector>

#include <visualization/language/kLiterals.hpp>
#include <visualization/message/kMessageType.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class aMessage
{
  public:
    aMessage(const model::visualization::message::aMessage& message);
    aMessage(std::time_t date, model::visualization::message::kMessageType messageType,
             std::vector<model::visualization::language::kLiterals> literals,
             std::vector<std::string> data);

    virtual std::time_t getDate() const;
    virtual model::visualization::message::kMessageType getMessageType() const;
    virtual std::vector<model::visualization::language::kLiterals> getLiterals() const;
    virtual std::vector<std::string> getData() const;

  protected:
    std::time_t mDate;
    model::visualization::message::kMessageType mMessageType;
    std::vector<model::visualization::language::kLiterals> mLiterals;
    std::vector<std::string> mData;
};

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_MESSAGE_AMESSAGE_HPP
