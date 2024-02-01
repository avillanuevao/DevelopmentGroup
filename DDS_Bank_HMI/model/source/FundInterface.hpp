#ifndef MODEL_FUNDINTERFACE_HPP
#define MODEL_FUNDINTERFACE_HPP

#include <FundType.hpp>
#include <FundIncreaseAmountInterface.hpp>
#include <FundDecreaseAmountInterface.hpp>
#include <FundSetFundTypeInterface.hpp>
#include <FundSetAmountInterface.hpp>
#include <FundGetParameterInterface.hpp>

#include <designPattern/SignalPublisher.hpp>
#include <signal/UpdatedFundSignal.hpp>

namespace model
{

class FundInterface :
        public model::FundIncreaseAmountInterface,
        public model::FundDecreaseAmountInterface,
        public model::FundSetAmountInterface,
        public model::FundSetFundTypeInterface,
        public model::FundGetParameterInterface,
        public utils::designPattern::SignalPublisher<model::signal::UpdatedFundSignal>

{
    public:
        FundInterface() = default;
};

}

#endif // FUNDINTERFACE_HPP
