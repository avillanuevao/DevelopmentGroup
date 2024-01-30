#include "DDSViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::AllFundsDDSInterface> allFunds):
    m_allFunds(allFunds)
{

}

void DDSViewModel::updateModel(model::Operation operation)
{
    m_allFunds->setAmount(operation.getFundTypeDestination(), operation.getAmount());
}

}
}
}
}
