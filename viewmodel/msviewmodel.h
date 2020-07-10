#ifndef MSVIEWMODEL_H
#define MSVIEWMODEL_H
#include"../common/etlbase.h"
#include"./sinks/msviewmodelsink.h"
#include"../model/msdatamodel.h"
#include"./commands/restartcommand.h"
#include"commands/leftblock.h"
#include"../common/parameter.h"

class MSViewModel : public Proxy_CommandNotification<MSViewModel>, public Proxy_PropertyNotification<MSViewModel>
{
public:
    MSViewModel();
    void set_model(const std::shared_ptr<MSDataModel>& model);
    MSDataModel& get_model() throw();

    std::shared_ptr<ICommandBase> get_restart_command() throw();
    std::shared_ptr<ICommandBase> get_leftblock_command() throw();

    int get_restart_num() throw();
    void set_restart_num(int num);
    std::shared_ptr<Block> get_block();
    bool restart(int row, int col, int boom_num);
    bool leftblock(int x_pos, int y_pos);

private:
    std::shared_ptr<MSDataModel> m_MSModel;    
    std::shared_ptr<RestartCommand> m_cmd_restart;
    std::shared_ptr<LeftBlockCommand> m_cmd_left;//ccx7.10

    std::shared_ptr<MSViewModelSink> m_sink;
    int m_restart_num;

};

#endif // MSVIEWMODEL_H
