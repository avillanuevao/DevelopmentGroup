#ifndef DDSVIEWMODEL_HPP
#define DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/operations/FundSetParameterInterface.hpp>
#include <model/source/operations/FundSetAmountByFundTypeInterface.hpp>

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
        DDSViewModel(std::shared_ptr<model::operations::FundSetParameterInterface> fundSetParameter,
                     std::shared_ptr<model::operations::FundSetAmountByFundTypeInterface> fundSetAmountByFundType);

        void updateFundType(model::operations::FundType fundType);
        void updateAmount(model::operations::FundType fundType, int amount);

    private:
        std::shared_ptr<model::operations::FundSetParameterInterface> m_fundSetParameter;
        std::shared_ptr<model::operations::FundSetAmountByFundTypeInterface> m_fundSetAmountByFundType;

};

}
}
}
}

#endif // DDSVIEWMODEL_HPP
