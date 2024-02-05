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

DDSViewModel::DDSViewModel(std::shared_ptr<model::FundSetAmountInterface> fund):
    m_fund(fund)
{

}

void DDSViewModel::updateModel(model::FundType fundType, int amount)
{
    m_fund->setAmount(amount);
}

}
}
}
}
