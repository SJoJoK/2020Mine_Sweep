#include "leftblock.h"
#include "../msviewmodel.h"
//ccx 7.10
LeftBlockCommand::LeftBlockCommand(MSViewModel* p) throw(): m_pVM(p),m_lparam(3,3)
{

}

void LeftBlockCommand::SetParameter(const std::any& param)
{
    m_lparam = std::any_cast<PosParameter>(param);
    //qDebug()<<"setpara";
}

void LeftBlockCommand::Exec()
{
    int i,j;
    i = m_lparam.i;
    j = m_lparam.j;
    qDebug()<<"postion is"<<i<<j;
    bool b_result = m_pVM->leftblock(i,j);
    m_pVM->Fire_OnCommandComplete("leftblockclk", b_result);
}
