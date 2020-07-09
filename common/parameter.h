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

#endif // PARAMETER_H
