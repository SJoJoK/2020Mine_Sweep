#include "msdatamodel.h"

MSDataModel::MSDataModel():restart_num(0),b(std::make_shared<Block>(5,5,1))
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
    restart_num = 1;//useless？
    b = std::make_shared<Block>(row,col,boom_num);
    qDebug()<<b->get_row()<<b->get_col()<<b->get_boom_num();
    Fire_OnPropertyChanged("restart_num");
    return true;
}
bool MSDataModel::leftblock(int x_pos, int y_pos){
    //change p[x_pos][y_pos].is_show

    b->p[x_pos][y_pos].set_show(1);
    qDebug()<<x_pos<<y_pos<<b->p[x_pos][y_pos].get_show()<<"setsquaresuccess";

    Fire_OnPropertyChanged("leftblockclk");
    return true;
}
