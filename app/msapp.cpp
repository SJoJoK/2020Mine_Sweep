#include "msapp.h"
MSApp::MSApp()
{

}
MSApp::~MSApp() throw()
{

}
bool MSApp::Init(MainWindow& w)
{


    //objects
    std::shared_ptr<MSDataModel> spModel(std::make_shared<MSDataModel>());
    m_spViewModel = std::make_shared<MSViewModel>();
    m_spViewModel->set_model(spModel);
    //binding
    w.m_pVM=m_spViewModel;
    // properties
    w.set_restart_num(m_spViewModel->get_restart_num());
    w.set_block(m_spViewModel->get_block());
    // commands
    w.set_restart_command(m_spViewModel->get_restart_command());
    // notifications
    m_spViewModel->AddPropertyNotification(w.get_propertty_sink());
    m_spViewModel->AddCommandNotification(w.get_command_sink());
    w.setWindowTitle("Mine Sweeping");
    w.show();
    w.update();
    return true;
}
