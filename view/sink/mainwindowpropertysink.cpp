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
    if( str == "block" )
    {
        m_pW->update();
    }
    if( str == "win" )
    {
		m_pW->update();
        QMessageBox::information(NULL,"提示","you win!");      
    }
    if( str == "lose")
    {
		m_pW->update();
        QMessageBox::information(NULL,"提示","you lose!");       
    }
}
