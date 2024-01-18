#ifndef DDSVIEWMODEL_HPP
#define DDSVIEWMODEL_HPP

#include <memory>

#include <model/AllFunds.hpp>
#include <model/Operation.hpp>

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
        DDSViewModel(std::shared_ptr<model::AllFunds> allFunds);

        void updateModel(model::Operation operation);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;

};

}
}
}
}

#endif // DDSVIEWMODEL_HPP
