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

PosParameter::PosParameter(int x,int y){
    this->i=x;
    this->j=y;
}
PosParameter& PosParameter::operator=(const PosParameter &src){
    if( this != &src ) {
        i = src.i;
        j = src.j;
    }
    return *this;
}
PosParameter& PosParameter::operator=(PosParameter &&src){
    if( this != &src ) {
        i = src.i;
        j = src.j;
    }
    return *this;
}
PosParameter::PosParameter() throw(){

}
PosParameter::PosParameter(const PosParameter& src):i(src.i),j(src.j){

}
PosParameter::PosParameter(PosParameter&& src){
    i = static_cast<int&&>(src.i);
    j = static_cast<int&&>(src.j);
}

SettingParameter::SettingParameter(SETTING x,int row,int col,int boom_num){
    this->setting=x;
    this->row=row;
    this->col=col;
    this->boom_num=boom_num;
}
SettingParameter& SettingParameter::operator=(const SettingParameter &src){
    if( this != &src ) {
        this->setting=src.setting;
        this->row=src.row;
        this->col=src.col;
        this->boom_num=src.boom_num;
    }
    return *this;
}
SettingParameter& SettingParameter::operator=(SettingParameter &&src){
    if( this != &src ) {
        this->setting=src.setting;
        this->row=src.row;
        this->col=src.col;
        this->boom_num=src.boom_num;
    }
    return *this;
}
SettingParameter::SettingParameter() throw(){

}
SettingParameter::SettingParameter(const SettingParameter& src):setting(src.setting){

}
SettingParameter::SettingParameter(SettingParameter&& src){
    setting = static_cast<SETTING&&>(src.setting);
    row = static_cast<int&&>(src.row);
    col = static_cast<int&&>(src.col);
    boom_num = static_cast<int&&>(src.boom_num);
}

UserParameter::UserParameter() throw()
{

}
UserParameter::UserParameter(const UserParameter& src)
{
    this->name=src.name;
    this->time=src.time;
}
UserParameter::UserParameter(UserParameter&& src)
{
    name=static_cast<QString&&>(src.name);
    time=static_cast<int&&>(src.time);
}

UserParameter::UserParameter(QString name, int time)
{
    this->name=name;
    this->time=time;
}
UserParameter& UserParameter::operator=(const UserParameter& src)
{
    if(this!=&src)
    {
        this->name=src.name;
        this->time=src.time;
    }
    return *this;
}
UserParameter& UserParameter::operator=(UserParameter&& src)
{
    if(this!=&src)
    {
        this->name=src.name;
        this->time=src.time;
    }
    return *this;
}
