#include "msviewmodelsink.h"
#include "../msviewmodel.h"
MSViewModelSink::MSViewModelSink(MSViewModel* p) throw():m_pVM(p)
{

}

void MSViewModelSink::OnPropertyChanged(const std::string &str)
{
    if(str=="restart_num")
    {
        m_pVM->set_restart_num(m_pVM->get_model().get_restart_num());
        m_pVM->Fire_OnPropertyChanged(str);
    }
}
