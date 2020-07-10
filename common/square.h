#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    bool get_boom();
    bool get_flag();
    bool get_mark();
    bool get_show();//ccx 7.10
    void set_boom(bool x);
    void set_flag(bool x);
    void set_mark(bool x);
    void set_show(bool x);//ccx 7.10
    int get_sur();
    void set_sur(int sur);
private:
    bool is_boom;
    bool is_flag;
    bool is_mark;
    bool is_show;//ccx 7.10
    int sur_boom;
};

#endif // SQUARE_H
