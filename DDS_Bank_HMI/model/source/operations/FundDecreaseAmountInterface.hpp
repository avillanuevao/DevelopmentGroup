#ifndef MODEL_OPERATIONS_FUNDDECREASEAMOUNTINTERFACE_HPP
#define MODEL_OPERATIONS_FUNDDECREASEAMOUNTINTERFACE_HPP

namespace model
{
namespace operations
{

class FundDecreaseAmountInterface
{
    public:
        FundDecreaseAmountInterface() = default;

        virtual void decreaseAmount(int amount) = 0;
};

}
}

#endif // MODEL_OPERATIONS_FUNDDECREASEAMOUNTINTERFACE_HPP
