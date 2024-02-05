#ifndef DDSVIEWMODEL_HPP
#define DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/FundSetParameterInterface.hpp>

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
        DDSViewModel(std::shared_ptr<model::FundSetParameterInterface> fund);

        void updateAmount(int amount);
        void updateFundType(model::FundType fundType);

    private:
        std::shared_ptr<model::FundSetParameterInterface> m_fund;

};

}
}
}
}

#endif // DDSVIEWMODEL_HPP
