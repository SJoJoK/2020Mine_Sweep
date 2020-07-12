#include "mainwindowpropertysink.h"
#include "../mainwindow.h"
MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str)
{
    if( str == "block" )
    {
        //m_pW->time_init();
        m_pW->update();
    }
    if( str == "win" )
    {
		m_pW->update();
        QMessageBox::information(NULL,"Congratulation","you win!");
    }
    if( str == "lose")
    {
		m_pW->update();
        QMessageBox::information(NULL,"Sorry","You lose!");
    }
}
