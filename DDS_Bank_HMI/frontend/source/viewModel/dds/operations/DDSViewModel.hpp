#ifndef DDSVIEWMODEL_HPP
#define DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/FundSetParameterInterface.hpp>
#include <model/source/FundSetAmountByFundTypeInterface.hpp>

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
        DDSViewModel(std::shared_ptr<model::FundSetParameterInterface> fundSetParameter,
                     std::shared_ptr<model::FundSetAmountByFundTypeInterface> fundSetAmountByFundType);

        void updateFundType(model::FundType fundType);
        void updateAmount(model::FundType fundType, int amount);

    private:
        std::shared_ptr<model::FundSetParameterInterface> m_fundSetParameter;
        std::shared_ptr<model::FundSetAmountByFundTypeInterface> m_fundSetAmountByFundType;

};

}
}
}
}

#endif // DDSVIEWMODEL_HPP
