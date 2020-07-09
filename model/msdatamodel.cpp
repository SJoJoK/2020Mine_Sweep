#include "msdatamodel.h"

MSDataModel::MSDataModel():restart_num(0),b(std::make_shared<Block>(1,1,1))
{

}

int MSDataModel::get_restart_num() throw()
{
    return restart_num;
}
std::shared_ptr<Block> MSDataModel :: get_block() throw()
{
    return b;
}
bool MSDataModel :: restart(int row, int col, int boom_num)
{
    restart_num = 1;//好像没啥用？
    b = std::make_shared<Block>(row,col,boom_num);
    qDebug()<<b->get_row()<<b->get_col()<<b->get_boom_num();
    Fire_OnPropertyChanged("restart_num");
    return true;
}
