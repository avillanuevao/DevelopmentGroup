#ifndef BACKEND_CONTROLLER_OPERATIONS_SELECTFUNDCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SELECTFUNDCONTROLLER_HPP

#include <memory>

#include <model/source/operations/kFundType.hpp>
#include <model/source/operations/iFundSetParameter.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class SelectFundController
{
    public:
        SelectFundController(std::shared_ptr<model::operations::iFundSetParameter> fund);

        void selectFundType(model::operations::kFundType fundType);

    private:
        std::shared_ptr<model::operations::iFundSetParameter> m_fund;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_SELECTFUNDCONTROLLER_HPP
