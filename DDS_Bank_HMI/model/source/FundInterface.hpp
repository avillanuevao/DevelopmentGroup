#ifndef MODEL_FUNDINTERFACE_HPP
#define MODEL_FUNDINTERFACE_HPP

#include <FundType.hpp>
#include <FundIncreaseAmountInterface.hpp>
#include <FundDecreaseAmountInterface.hpp>
#include <FundSetParameterInterface.hpp>
#include <FundGetAmountInterface.hpp>

#include <designPattern/SignalPublisher.hpp>
#include <signal/UpdatedFundSignal.hpp>
#include <signal/UpdatedFundTypeSignal.hpp>

namespace model
{

class FundInterface :
        public model::FundIncreaseAmountInterface,
        public model::FundDecreaseAmountInterface,
        public model::FundSetParameterInterface,
        public model::FundGetAmountInterface,
        public utils::designPattern::SignalPublisher<model::signal::UpdatedFundSignal>,
        public utils::designPattern::SignalPublisher<model::signal::UpdatedFundTypeSignal>

{
    public:
        FundInterface() = default;
};

}

#endif // FUNDINTERFACE_HPP
