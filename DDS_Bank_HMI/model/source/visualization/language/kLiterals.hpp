#ifndef MODEL_VISUALIZATION_LANGUAGE_KLITERALS_HPP
#define MODEL_VISUALIZATION_LANGUAGE_KLITERALS_HPP

#include <enum.hpp>

namespace model
{
namespace visualization
{
namespace language
{

BETTER_ENUM(kLiterals, int,
            Fund,
            Deposit,
            Withdraw,
            Transfer,
            Success,
            Failure,
            Warning,
            Savings,
            Housing,
            Value1,
            Value2,
            Value3,
            Value4,
            Value5)

}  // namespace language
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_LANGUAGE_KLITERALS_HPP
