#include "mainwindowcommandsink.h"
#include "../mainwindow.h"
MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if( str == "restart" )
    {
         m_pW->paint_flag=0;
         m_pW->update();
    }
    if( str == "leftblockclk" )
    {
        //
    }
    if( str == "rightclockclk" )
    {
        //
    }
}
