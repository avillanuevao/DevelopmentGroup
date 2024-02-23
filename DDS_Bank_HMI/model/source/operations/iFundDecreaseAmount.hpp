#ifndef MODEL_OPERATIONS_IFUNDDECREASEAMOUNT_HPP
#define MODEL_OPERATIONS_IFUNDDECREASEAMOUNT_HPP

namespace model
{
namespace operations
{

class iFundDecreaseAmount
{
  public:
    iFundDecreaseAmount() = default;

    virtual void decreaseAmount(int amount) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDDECREASEAMOUNT_HPP
