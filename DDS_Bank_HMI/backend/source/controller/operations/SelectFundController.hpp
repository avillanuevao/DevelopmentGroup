#ifndef BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundType.hpp>
#include <model/source/operations/FundSetParameterInterface.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class SelectFundController
{
    public:
        SelectFundController(std::shared_ptr<model::operations::FundSetParameterInterface> fund);

        void selectFundType(model::operations::FundType fundType);

    private:
        std::shared_ptr<model::operations::FundSetParameterInterface> m_fund;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP
