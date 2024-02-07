#include "DDSViewModel.hpp"

#include <model/source/operations/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::operations::FundSetParameterInterface> fundSetParameter,
                           std::shared_ptr<model::operations::FundSetAmountByFundTypeInterface> fundSetAmountByFundType):
    m_fundSetParameter(fundSetParameter),
    m_fundSetAmountByFundType(fundSetAmountByFundType)
{

}

void DDSViewModel::updateFundType(model::operations::FundType fundType)
{
    m_fundSetParameter->setFundType(fundType);
}

void DDSViewModel::updateAmount(model::operations::FundType fundType, int amount)
{
    m_fundSetAmountByFundType->setAmount(fundType, amount);
}

}
}
}
}
