#ifndef MODEL_FUNDDECREASEAMOUNTINTERFACE_HPP
#define MODEL_FUNDDECREASEAMOUNTINTERFACE_HPP

namespace model
{

class FundDecreaseAmountInterface
{
    public:
        FundDecreaseAmountInterface() = default;

        virtual void decreaseAmount(int amount) = 0;
};

}

#endif // MODEL_FUNDDECREASEAMOUNTINTERFACE_HPP
