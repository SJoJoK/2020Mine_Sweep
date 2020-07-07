#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    bool get_boom();
    bool get_flag();
    bool get_mark();
    void set_boom(bool x);
    void set_flag(bool x);
    void set_mark(bool x);
    int get_sur();
    void set_sur(int sur);
private:
    bool is_boom;//是否是炸弹
    bool is_flag;//是否是旗子
    bool is_mark;//是否是标记
    int sur_boom;//周围的炸弹数
};

#endif // SQUARE_H
