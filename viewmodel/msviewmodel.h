#ifndef MSVIEWMODEL_H
#define MSVIEWMODEL_H
#include"../common/etlbase.h"
#include"./sinks/msviewmodelsink.h"
#include"../model/msdatamodel.h"
#include"./commands/restartcommand.h"
#include"../common/parameter.h"

class MSViewModel : public Proxy_CommandNotification<MSViewModel>, public Proxy_PropertyNotification<MSViewModel>
{
public:
    MSViewModel();
    void set_model(const std::shared_ptr<MSDataModel>& model);
    MSDataModel& get_model() throw();

    std::shared_ptr<ICommandBase> get_restart_command() throw();

    int get_restart_num() throw();
    void set_restart_num(int num);
    bool restart(int row, int col, int boom_num);
private:
    std::shared_ptr<MSDataModel> m_MSModel;
    int m_restart_num;
    std::shared_ptr<RestartCommand> m_cmd_restart;
    std::shared_ptr<MSViewModelSink> m_sink;

};

#endif // MSVIEWMODEL_H
