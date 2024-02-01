#ifndef MODEL_FUNDSETAMOUNTINTERFACE_HPP
#define MODEL_FUNDSETAMOUNTINTERFACE_HPP

namespace model
{

class FundSetAmountInterface
{
    public:
        FundSetAmountInterface() = default;

        virtual void setAmount(int amount) = 0;
};

}

#endif // MODEL_FUNDSETAMOUNTINTERFACE_HPP
