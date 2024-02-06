#ifndef BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP

#include <memory>

#include <model/source/FundType.hpp>
#include <model/source/FundSetParameterInterface.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

class SelectFundController
{
    public:
        SelectFundController(std::shared_ptr<model::FundSetParameterInterface> fund);

        void selectFundType(model::FundType fundType);

    private:
        std::shared_ptr<model::FundSetParameterInterface> m_fund;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_SELECTFUNDCONTROLLER_HPP
