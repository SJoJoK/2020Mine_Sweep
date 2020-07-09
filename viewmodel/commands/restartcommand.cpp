#include "restartcommand.h"
#include "../msviewmodel.h"
RestartCommand::RestartCommand(MSViewModel* p) throw(): m_pVM(p)
{
    ;
}

void RestartCommand::SetParameter(const std::any &param)
{
    ;
}

void RestartCommand::Exec()
{
    bool b_result = m_pVM->restart();
    m_pVM->Fire_OnCommandComplete("restart", b_result);
}
