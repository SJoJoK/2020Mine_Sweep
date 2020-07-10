#include "block.h"

Block::Block(int row, int col, int boom_num)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    p=new Square*[row];
    for (int i = 0; i < row ; i++)
    {
        p[i] = new Square [col];
    }
    for (int i = 0; i < boom_num; i++)
    {
        int index = qrand()%(row*col);
        if(p[index/col][index%col].get_boom()==false)
        {
            p[index/col][index%col].set_boom(true);
        }
        else
        {
            i--;
            continue;
        }
    }
    for (int i = 0; i < row ; i++)
    {
        int sur=0;
        for (int j = 0; j < col ; j++)
        {
            for (int tmp_row = i-1; tmp_row <= i+1; tmp_row++)
            {
                for (int tmp_col = j-1; tmp_col <= j+1; tmp_col++)
                {
                    if(tmp_row<0||tmp_row>=row||tmp_col<0||tmp_col>=0) continue;
                    if(p[tmp_row][tmp_col].get_boom()==true) sur++;
                }
            }
            p[i][j].set_sur(sur);
        }
    }
    this->col=col;
    this->row=row;
    this->boom_num=boom_num;
    this->flag=0;
    this->time=0;
}
Block::~Block()
{
    for(int i =0;i<row;i++)
    {
        delete[]  p[i];
    }
       delete [] p;
}
int Block::get_col()
{
    return col;
}
int Block::get_row()
{
    return row;
}
int Block::get_boom_num()
{
    return boom_num;
}
int Block::get_flag_num()
{
    return flag;
}
int Block:: get_time()
{
    return time;
}
void Block::set_flag_num(int num)
{
    flag=num;
}
void Block::change_flag_num(int d_num)
{
    flag+=d_num;
}
void Block::set_time(int time)
{
    this->time = time;
}
void Block::change_time(int d_time)
{
    this->time += d_time;
}

//recursively block set show (when sur_boom == 0)
void Block::bset_show(int x, int y){
    if(this->p[x][y].visit==1) return;
    this->p[x][y].set_show(1);
    this->p[x][y].visit = 1;
    qDebug()<<"set1 success";
    //3*3 traversal
    for(int blockRow = x-1; blockRow <= x+1; blockRow++){
        for(int blockCol = y-1; blockCol <=y+1; blockCol++){
            //edge square
            if(blockRow<0||blockCol<0||blockRow>=this->get_row()||blockCol>=this->get_col())
               continue;
            //if sur==0, continue executing
            if(this->p[blockRow][blockCol].get_sur()==0 && this->p[blockRow][blockCol].visit==0){
                qDebug()<<"recur";
                bset_show(blockRow,blockCol);
            }
        }
    }
}

void Block::reset_visit(int x, int y){
    for(int blockRow = x-1; blockRow <= x+1; blockRow++){
        for(int blockCol = y-1; blockCol <=y+1; blockCol++){
            //edge square
            if(blockRow<0||blockCol<0||blockRow>=this->get_row()||blockCol>=this->get_col())
               continue;
            this->p[blockRow][blockCol].visit= 0;
        }
    }
}
