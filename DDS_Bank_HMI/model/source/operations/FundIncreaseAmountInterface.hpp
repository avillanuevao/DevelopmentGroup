#ifndef MODEL_OPERATIONS_FUNDINCREASEAMOUNTINTERFACE_HPP
#define MODEL_OPERATIONS_FUNDINCREASEAMOUNTINTERFACE_HPP

namespace model
{
namespace operations
{

class FundIncreaseAmountInterface
{
    public:
        FundIncreaseAmountInterface() = default;

        virtual void increaseAmount(int amount) = 0;
};

}
}

#endif // MODEL_OPERATIONS_FUNDINCREASEAMOUNTINTERFACE_HPP
