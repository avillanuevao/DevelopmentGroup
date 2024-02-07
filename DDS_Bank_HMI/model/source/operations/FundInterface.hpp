#ifndef MODEL_FUNDINTERFACE_HPP
#define MODEL_FUNDINTERFACE_HPP

#include <operations/FundType.hpp>
#include <operations/FundIncreaseAmountInterface.hpp>
#include <operations/FundDecreaseAmountInterface.hpp>
#include <operations/FundSetParameterInterface.hpp>
#include <operations/FundGetParametersInterface.hpp>

#include <designPattern/SignalPublisher.hpp>
#include <operations/signal/UpdatedFundSignal.hpp>
#include <operations/signal/UpdatedFundTypeSignal.hpp>

namespace model
{
namespace operations
{

class FundInterface :
        public model::operations::FundIncreaseAmountInterface,
        public model::operations::FundDecreaseAmountInterface,
        public model::operations::FundSetParameterInterface,
        public model::operations::FundGetParametersInterface,
        public utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundSignal>,
        public utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundTypeSignal>

{
    public:
        FundInterface() = default;
};

}


}

#endif // FUNDINTERFACE_HPP
