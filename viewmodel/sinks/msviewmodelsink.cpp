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
    if(str == "restart")
    {
        m_pVM->Fire_OnPropertyChanged(str);
    }
    //ccx 7.12
    if(str == "addrank")
    {
        m_pVM->Fire_OnPropertyChanged(str);
    }
}
