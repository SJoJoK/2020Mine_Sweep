#ifndef PARAMETER_H
#define PARAMETER_H
enum SETTING { JUNIOR, MIDDLE, SENIOR, CUSTOM };

class BlockParameter
{
public:
    BlockParameter() throw();
    BlockParameter(const BlockParameter& src);
    BlockParameter(BlockParameter&& src);

    BlockParameter(int a, int b, int c);
    BlockParameter& operator=(const BlockParameter& src);
    BlockParameter& operator=(BlockParameter&& src);
public:
    int row;
    int col;
    int boom_num;
};

//ccx 7.10
class PosParameter{
public:
    PosParameter() throw();
    PosParameter(const PosParameter& src);
    PosParameter(PosParameter&& src);

    PosParameter(int a, int b);
    PosParameter& operator=(const PosParameter& src);
    PosParameter& operator=(PosParameter&& src);
public:
    int i;
    int j;
};

class SettingParameter{
public:
    SETTING setting;
    int row;
    int col;
    int boom_num;
public:
    SettingParameter() throw();
    SettingParameter(const SettingParameter& src);
    SettingParameter(SettingParameter&& src);

    SettingParameter(SETTING x,int row,int col, int boom_num);
    SettingParameter& operator=(const SettingParameter& src);
    SettingParameter& operator=(SettingParameter&& src);
};
//ccx 7.12 add row/col/boom_num
#endif // PARAMETER_H
