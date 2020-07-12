#ifndef RESETBLOCKCOMMAND_H
#define RESETBLOCKCOMMAND_H

#include "../../common/etlbase.h"
#include "common/parameter.h"
class MSViewModel;

class ResetBlockCommand : public ICommandBase
{
public:
    ResetBlockCommand(MSViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    MSViewModel* m_pVM;

    SettingParameter m_param;
};

#endif // RESETBLOCKCOMMAND_H
