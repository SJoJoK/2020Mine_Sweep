#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    bool get_boom();
    bool get_flag();
    bool get_mark();
    bool get_show();
    void set_boom(bool x);
    void set_flag(bool x);
    void set_mark(bool x);
    void set_show(bool x);
    int get_sur();
    void set_sur(int sur);
private:
    bool is_boom;
    bool is_flag;
    bool is_mark;
    bool is_show;
    int sur_boom;
};

#endif // SQUARE_H
