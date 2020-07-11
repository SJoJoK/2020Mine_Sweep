#include "mainwindowcommandsink.h"
#include "../mainwindow.h"
MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if( str == "restart" )
    {
         //
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
