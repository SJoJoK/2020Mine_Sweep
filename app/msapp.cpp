#include "msapp.h"
MSApp::MSApp()
{

}
MSApp::~MSApp() throw()
{

}
bool MSApp::Init(MainWindow& w)
{
    w.setWindowTitle("Mine Sweeping");
    w.show();

    //objects
    std::shared_ptr<MSDataModel> spModel(std::make_shared<MSDataModel>());
    m_spViewModel = std::make_shared<MSViewModel>();
   // m_spViewModel->SetModel(spModel);
    //binding
    // properties
    //w.block.set_block(m_spViewModel->get_block());
    //w.block.set_time(m_spViewModel->get_time());
    // commands
    //w.set_RestartCommand(m_spViewModel->get_RestartCommand());
    // notifications
    //m_spViewModel->AddPropertyNotification(w.get_PropertySink());
    //m_spViewModel->AddCommandNotification(w.get_CommandSink());

    return true;
}
