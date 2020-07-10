#include "leftblock.h"
#include "../msviewmodel.h"
//ccx 7.10
LeftBlockCommand::LeftBlockCommand(MSViewModel* p) throw(): m_pVM(p),m_lparam(3,3)
{

}

void LeftBlockCommand::SetParameter(const std::any& param)
{
    m_lparam = std::any_cast<PositionParameter>(param);
    qDebug()<<"setpara";
}

void LeftBlockCommand::Exec()
{
    int x_pos,y_pos;
    x_pos = m_lparam.x_pos;
    y_pos = m_lparam.y_pos;
    qDebug()<<"inexec"<<x_pos<<y_pos;
    bool b_result = m_pVM->leftblock(x_pos,y_pos);
    m_pVM->Fire_OnCommandComplete("leftblockclk", b_result);
}
