#include "msdatamodel.h"

<<<<<<< HEAD
MSDataModel::MSDataModel():restart_num(0),b(std::make_shared<Block>(7,7,1))
=======
MSDataModel::MSDataModel():restart_num(0),b(std::make_shared<Block>(1,1,1))
>>>>>>> view
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
<<<<<<< HEAD
    restart_num = 1;//useless？
=======
    restart_num = 1;//好像没啥用？
>>>>>>> view
    b = std::make_shared<Block>(row,col,boom_num);
    qDebug()<<b->get_row()<<b->get_col()<<b->get_boom_num();
    Fire_OnPropertyChanged("restart_num");
    return true;
}
bool MSDataModel::leftblock(int x_pos, int y_pos){
    //change p[x_pos][y_pos].is_show
    //b->p[x_pos][y_pos].set_show(1);
    b->bset_show(x_pos, y_pos);
    b->reset_visit(x_pos, y_pos);
    qDebug()<<x_pos<<y_pos<<b->p[x_pos][y_pos].get_show()<<"setsquaresuccess";

    Fire_OnPropertyChanged("block");
    return true;
}
