#include "DDSViewModel.hpp"

#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::operations::iFundSetParameter> fundSetParameter,
                           std::shared_ptr<model::operations::iFundSetAmountByFundType> fundSetAmountByFundType):
    m_fundSetParameter(fundSetParameter),
    m_fundSetAmountByFundType(fundSetAmountByFundType)
{

}

void DDSViewModel::updateFundType(model::operations::kFundType fundType)
{
    m_fundSetParameter->setFundType(fundType);
}

void DDSViewModel::updateAmount(model::operations::kFundType fundType, int amount)
{
    m_fundSetAmountByFundType->setAmount(fundType, amount);
}

}
}
}
}
