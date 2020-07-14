#ifndef RANKADDCOMMAND_H
#define RANKADDCOMMAND_H

#include "../../common/etlbase.h"
#include "common/parameter.h"
class MSViewModel;

class RankAddCommand : public ICommandBase
{
public:
    RankAddCommand(MSViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    MSViewModel* m_pVM;
    
    UserParameter m_param;

};

#endif // RANKADDCOMMAND_H
