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

DDSViewModel::DDSViewModel(std::shared_ptr<model::FundSetParameterInterface> fund):
    m_fund(fund)
{

}

void DDSViewModel::updateAmount(int amount)
{
    m_fund->setAmount(amount);
}

void DDSViewModel::updateFundType(model::FundType fundType)
{
    m_fund->setFundType(fundType);
}

}
}
}
}
