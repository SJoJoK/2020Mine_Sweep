#include "msviewmodelsink.h"
#include "../msviewmodel.h"
MSViewModelSink::MSViewModelSink(MSViewModel* p) throw():m_pVM(p)
{

}

void MSViewModelSink::OnPropertyChanged(const std::string &str)
{
    if (str == "block")
    {
        m_pVM->Fire_OnPropertyChanged(str);
    }
    if (str == "lose")
    {
        m_pVM->Fire_OnPropertyChanged(str);
    }
    if (str == "win")
    {
        m_pVM->Fire_OnPropertyChanged(str);
    }
}
