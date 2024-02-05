#ifndef DDSVIEWMODEL_HPP
#define DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/FundSetAmountInterface.hpp>

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
        DDSViewModel(std::shared_ptr<model::FundSetAmountInterface> fund);

        void updateModel(model::FundType fundType, int amount);

    private:
        std::shared_ptr<model::FundSetAmountInterface> m_fund;

};

}
}
}
}

#endif // DDSVIEWMODEL_HPP
