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
    m_spViewModel->set_model(spModel);
    //binding
    // properties
    w.paint_restart_num(m_spViewModel->get_restart_num());
    // commands
    w.set_restart_command(m_spViewModel->get_restart_command());
    // notifications
    m_spViewModel->AddPropertyNotification(w.get_propertty_sink());
    m_spViewModel->AddCommandNotification(w.get_command_sink());

    return true;
}
