#ifndef FRONTEND_VIEWMODEL_DDS_OPERATIONS_DDSVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_DDS_OPERATIONS_DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/operations/iFundSetParameter.hpp>
#include <model/source/operations/iFundSetAmountByFundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

class DDSViewModel
{
    public:
        DDSViewModel(std::shared_ptr<model::operations::iFundSetParameter> fundSetParameter,
                     std::shared_ptr<model::operations::iFundSetAmountByFundType> fundSetAmountByFundType);

        void updateFundType(model::operations::kFundType fundType);
        void updateAmount(model::operations::kFundType fundType, int amount);

    private:
        std::shared_ptr<model::operations::iFundSetParameter> m_fundSetParameter;
        std::shared_ptr<model::operations::iFundSetAmountByFundType> m_fundSetAmountByFundType;

};

}
}
}
}

#endif // FRONTEND_VIEWMODEL_DDS_OPERATIONS_DDSVIEWMODEL_HPP
