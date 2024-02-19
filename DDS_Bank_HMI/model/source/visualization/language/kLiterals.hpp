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
            kFund,
            kDeposit,
            kWithdraw,
            kTransfer,
            kSuccess,
            kFailure,
            kWarning,
            kSavings,
            kHousing,
            kValue1,
            kValue2,
            kValue3,
            kValue4,
            kValue5)

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_KLITERALS_HPP
