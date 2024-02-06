#include "DDSViewModel.hpp"

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::FundSetParameterInterface> fundSetParameter,
                           std::shared_ptr<model::FundSetAmountByFundTypeInterface> fundSetAmountByFundType):
    m_fundSetParameter(fundSetParameter),
    m_fundSetAmountByFundType(fundSetAmountByFundType)
{

}

void DDSViewModel::updateFundType(model::FundType fundType)
{
    m_fundSetParameter->setFundType(fundType);
}

void DDSViewModel::updateAmount(model::FundType fundType, int amount)
{
    m_fundSetAmountByFundType->setAmountByFundType(fundType, amount);
}

}
}
}
}
