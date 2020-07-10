#include "msviewmodel.h"

MSViewModel::MSViewModel() : m_restart_num(0),
                                m_cmd_restart(std::make_shared<RestartCommand>(this)),
                                m_sink(std::make_shared<MSViewModelSink>(this))
{
}

void MSViewModel::set_model(const std::shared_ptr<MSDataModel>& model)
{
    m_MSModel = model;
    m_MSModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}

int MSViewModel::get_restart_num() throw()
{
    return m_restart_num;
}

void MSViewModel:: set_restart_num(int num)
{
    m_restart_num=num;
}
std::shared_ptr<ICommandBase> MSViewModel::get_restart_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmd_restart);
}
std::shared_ptr<Block> MSViewModel ::get_block()
{
    return m_MSModel->get_block();
}
MSDataModel& MSViewModel::get_model() throw()
{
    return *m_MSModel;
}
bool MSViewModel::restart(int row, int col, int boom_num)
{
    return m_MSModel->restart(row,col,boom_num);
}
