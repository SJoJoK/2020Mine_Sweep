#ifndef MSDATAMODEL_H
#define MSDATAMODEL_H
#include"../common/etlbase.h"
#include"../common/block.h"
#include <QtDebug>

class MSDataModel : public Proxy_PropertyNotification<MSDataModel>
{
public:
    MSDataModel();
    int get_restart_num() throw();
    std::shared_ptr<Block> get_block() throw();
    bool restart(int row, int col, int boom_num);
    bool leftblock(int x_pos, int y_pos);
    bool rightblock(int x_pos, int y_pos);
private:
    int restart_num;
    std::shared_ptr<Block> b;
};

#endif // MSDATAMODEL_H
