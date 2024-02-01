#ifndef MODEL_FUNDINCREASEAMOUNTINTERFACE_HPP
#define MODEL_FUNDINCREASEAMOUNTINTERFACE_HPP

namespace model
{

class FundIncreaseAmountInterface
{
    public:
        FundIncreaseAmountInterface() = default;

        virtual void increaseAmount(int amount) = 0;
};

}

#endif // MODEL_FUNDINCREASEAMOUNTINTERFACE_HPP
