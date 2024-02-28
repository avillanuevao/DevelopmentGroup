#ifndef BACKEND_CONTROLLER_OPERATIONS_SAVEFUND_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SAVEFUND_HPP

#include <memory>
#include <fstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <model/source/operations/iFundGetAmountByFundType.hpp>
#include <model/source/operations/kFundType.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class SaveFund
{
  public:
    SaveFund(std::shared_ptr<model::operations::iFundGetAmountByFundType> fund);

    void saveFund(model::operations::kFundType fundChanged);

  private:
    std::shared_ptr<model::operations::iFundGetAmountByFundType> mFund;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_OPERATIONS_SAVEFUND_HPP
