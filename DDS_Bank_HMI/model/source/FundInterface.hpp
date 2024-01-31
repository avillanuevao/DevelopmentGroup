#ifndef MODEL_FUNDINTERFACE_HPP
#define MODEL_FUNDINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundInterface
{
    public:
        FundInterface() = default;
        virtual void increaseAmount(int amount) = 0;
        virtual void decreaseAmount(int amount) = 0;

        virtual model::FundType getFundType() const = 0;
        virtual int getAmount() const = 0;
        virtual void setAmount(int newAmount) noexcept(false) = 0;
};

}

#endif // FUNDINTERFACE_HPP
