#include "parameter.h"

BlockParameter::BlockParameter(int a, int b, int c)
{
    this->row = a;
    this->col = b;
    this->boom_num = c;
}
BlockParameter& BlockParameter::operator=(const BlockParameter& src)
{
    if( this != &src ) {
        row = src.row;
        col = src.col;
        boom_num = src.boom_num;
    }
    return *this;
}

BlockParameter& BlockParameter::operator=(BlockParameter&& src)
{
    if( this != &src ) {
        row = src.row;
        col = src.col;
        boom_num = src.boom_num;
    }
    return *this;
}
BlockParameter::BlockParameter() throw(){

}
BlockParameter::BlockParameter(const BlockParameter& src):row(src.row), col(src.col), boom_num(src.boom_num)
{
}
BlockParameter::BlockParameter(BlockParameter&& src){
    row = static_cast<int&&>(src.row);
    col = static_cast<int&&>(src.col);
    boom_num = static_cast<int&&>(src.boom_num);
}

//ccx 7.10
PositionParameter::PositionParameter(int a, int b)
{
    this->x_pos = a;
    this->y_pos = b;
}
PositionParameter& PositionParameter::operator=(const PositionParameter& src)
{
    if( this != &src ) {
        x_pos = src.x_pos;
        y_pos = src.y_pos;
    }
    return *this;
}

PositionParameter& PositionParameter::operator=(PositionParameter&& src)
{
    if( this != &src ) {
        x_pos = src.x_pos;
        y_pos = src.y_pos;
    }
    return *this;
}
PositionParameter::PositionParameter() throw(){

}
PositionParameter::PositionParameter(const PositionParameter& src):x_pos(src.x_pos), y_pos(src.y_pos)
{
}
PositionParameter::PositionParameter(PositionParameter&& src){
    x_pos = static_cast<int&&>(src.x_pos);
    y_pos = static_cast<int&&>(src.y_pos);
}
