#ifndef MSDATAMODEL_H
#define MSDATAMODEL_H
#include"../common/etlbase.h"
#include"../common/block.h"
#include <Qdebug.h>

class MSDataModel : public Proxy_PropertyNotification<MSDataModel>
{
public:
    MSDataModel();
    int get_restart_num() throw();
    std::shared_ptr<Block> get_block() throw();
    bool restart(int row, int col, int boom_num);
private:
    int restart_num;
    std::shared_ptr<Block> b;
};

#endif // MSDATAMODEL_H
