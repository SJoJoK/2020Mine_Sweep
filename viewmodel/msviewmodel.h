#ifndef MSVIEWMODEL_H
#define MSVIEWMODEL_H

#include"../common/etlbase.h"
#include"./sinks/msviewmodelsink.h"
#include"../model/msdatamodel.h"
#include"./commands/restartcommand.h"
#include"commands/leftblock.h"
#include"commands/rightblockcommand.h"
#include"../common/parameter.h"
#include"commands/resetblockcommand.h"
#include"commands/rankaddcommand.h"


class MSViewModel : public Proxy_CommandNotification<MSViewModel>, public Proxy_PropertyNotification<MSViewModel>
{
public:
    MSViewModel();
    void set_model(const std::shared_ptr<MSDataModel>& model);
    MSDataModel& get_model() throw();

    std::shared_ptr<ICommandBase> get_restart_command() throw();
    std::shared_ptr<ICommandBase> get_leftblock_command() throw();
    std::shared_ptr<ICommandBase> get_rightblock_command() throw();
    std::shared_ptr<ICommandBase> get_resetblock_command() throw();
    std::shared_ptr<ICommandBase> get_rankadd_command() throw();//ranklist
    std::shared_ptr<Block> get_block();
    bool restart(int row, int col, int boom_num);
    bool leftblock(int x_pos, int y_pos);
    bool rightblock(int x_pos, int y_pos);
    bool resetblock(SETTING setting,int row, int col, int boom_num);
    bool rankadd(UserParameter userinfo);

private:
    std::shared_ptr<MSDataModel> m_MSModel;    
    std::shared_ptr<RestartCommand> m_cmd_restart;
    std::shared_ptr<LeftBlockCommand> m_cmd_left;//ccx7.10
    std::shared_ptr<RightBlockCommand> m_cmd_right;//ccx7.11
    std::shared_ptr<ResetBlockCommand> m_cmd_resetblock;//ccx7.12
    std::shared_ptr<RankAddCommand > m_cmd_rankadd;//ccx7.13

    std::shared_ptr<MSViewModelSink> m_sink;

};

#endif // MSVIEWMODEL_H
