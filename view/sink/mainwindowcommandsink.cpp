#include "mainwindowcommandsink.h"
#include "../mainwindow.h"
MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if( str == "restart" )
    {
         QMessageBox::information(NULL,"恭喜","成功+1");
    }
    if(str=="leftblockclick")
    {
        QMessageBox::information(NULL,"恭喜","leftclick");
    }
}
