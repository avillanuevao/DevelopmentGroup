#ifndef MODEL_OPERATIONS_IFUND_HPP
#define MODEL_OPERATIONS_IFUND_HPP

#include <designPattern/SignalPublisher.hpp>
#include <operations/iFundDecreaseAmount.hpp>
#include <operations/iFundGetParameters.hpp>
#include <operations/iFundIncreaseAmount.hpp>
#include <operations/iFundSetParameter.hpp>
#include <operations/kFundType.hpp>
#include <operations/signal/UpdatedFund.hpp>
#include <operations/signal/UpdatedFundType.hpp>

namespace model
{
namespace operations
{

class iFund :
    public model::operations::iFundIncreaseAmount,
    public model::operations::iFundDecreaseAmount,
    public model::operations::iFundSetParameter,
    public model::operations::iFundGetParameters,
    public utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>,
    public utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>

{
  public:
    iFund() = default;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_FUNDINTERFACE_HPP
