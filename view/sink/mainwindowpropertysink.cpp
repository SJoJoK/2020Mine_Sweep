#include "mainwindowpropertysink.h"
#include "../mainwindow.h"
MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str)
{
    if( str == "restart_num" )
    {
        m_pW->update();
    }
    if( str == "leftblockclk" )
    {
        m_pW->update();
    }
}
