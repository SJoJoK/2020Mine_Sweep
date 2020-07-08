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
bool MSDataModel :: restart()
{
    restart_num++;
    b = std::make_shared<Block>(5,5,1);
    Fire_OnPropertyChanged("restart_num");
    return true;
}
