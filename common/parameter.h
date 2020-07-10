#ifndef PARAMETER_H
#define PARAMETER_H


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
class PositionParameter{
public:
    PositionParameter() throw();
    PositionParameter(const PositionParameter& src);
    PositionParameter(PositionParameter&& src);

    PositionParameter(int a, int b);
    PositionParameter& operator=(const PositionParameter& src);
    PositionParameter& operator=(PositionParameter&& src);
public:
    int x_pos;
    int y_pos;
};

#endif // PARAMETER_H
