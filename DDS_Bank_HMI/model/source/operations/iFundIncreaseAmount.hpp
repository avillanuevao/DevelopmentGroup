#ifndef MODEL_OPERATIONS_IFUNDINCREASEAMOUNT_HPP
#define MODEL_OPERATIONS_IFUNDINCREASEAMOUNT_HPP

namespace model
{
namespace operations
{

class iFundIncreaseAmount
{
  public:
    iFundIncreaseAmount() = default;

    virtual void increaseAmount(int amount) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDINCREASEAMOUNT_HPP
