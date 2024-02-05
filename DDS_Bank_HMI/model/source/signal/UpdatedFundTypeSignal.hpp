#ifndef MODEL_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP
#define MODEL_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP


#include <FundType.hpp>

namespace  model
{
namespace signal
{

class UpdatedFundTypeSignal
{
    public:
        UpdatedFundTypeSignal(model::FundType fundType);

        model::FundType getFundType() const;
        void setFundType(model::FundType newFundType);

private:
        model::FundType m_fundType;
};

}
}

#endif // MODEL_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP
