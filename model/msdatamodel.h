#ifndef MSDATAMODEL_H
#define MSDATAMODEL_H
#include"../common/etlbase.h"
#include"common/parameter.h"
#include"../common/block.h"
#include <QtDebug>

class MSDataModel : public Proxy_PropertyNotification<MSDataModel>
{
public:
    MSDataModel();
    std::shared_ptr<Block> get_block() throw();
    bool restart(int row, int col, int boom_num);
    bool leftblock(int x_pos, int y_pos);
    bool rightblock(int x_pos, int y_pos);
    bool resetblock(SETTING setting,int row, int col, int boom_num);
private:
    std::shared_ptr<Block> b;
};

#endif // MSDATAMODEL_H
