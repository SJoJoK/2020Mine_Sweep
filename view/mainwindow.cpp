#include "mainwindow.h"
#include "ui_mainwindow.h"
static int paint_flag=4;
int BLOCK_LENGTH=21;
int BLOCK_HEIGHT=21;
int TITLE_HEIGHT=63;
QPainter *paint_my_window;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sink_property(std::make_shared<MainWindowPropertySink>(this))
    , m_sink_command(std::make_shared<MainWindowCommandSink>(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    int LENGTH=B->get_col()*21;
    int HEIGHT=B->get_row()*21+63;
    this->setMinimumSize(LENGTH,HEIGHT);
    this->setMaximumSize(LENGTH*2,HEIGHT*2);
    this->resize(LENGTH,HEIGHT);
}

void MainWindow::set_restart_command(const std::shared_ptr<ICommandBase> &cmd) throw()
{
     m_cmd_restart = cmd;
}
void MainWindow::set_leftblock_command(const std::shared_ptr<ICommandBase> &cmd) throw()
{
     m_cmd_left = cmd;
}
std::shared_ptr<IPropertyNotification> MainWindow::get_propertty_sink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sink_property);
}

std::shared_ptr<ICommandNotification> MainWindow::get_command_sink() throw()
{
    return std::static_pointer_cast<ICommandNotification>(m_sink_command);
}

void MainWindow :: paintEvent(QPaintEvent * event)
{
    //paint_restart_num();
    QPainter painter(this);
    paint_my_window=&painter;
    QPixmap mine_title(":img/image/mine_title.bmp");
    QPixmap block_close(":img/image/block_close.bmp");
    QPixmap block_open(":img/image/block_open.bmp");
    QPixmap red_flag(":img/image/redflag.bmp");
    QPixmap keil_boom(":img/image/keilboom.bmp");
    QPixmap click_boom(":img/image/clickboom.bmp");
    QPixmap boom(":img/image/boom.bmp");
    QPixmap qq_smile(":img/image/smile.bmp");
    QPixmap qq_lose(":img/image/lose.bmp");
    QPixmap qq_pround(":img/image/proud.bmp");
    QPixmap ele_0(":img/image/ele0.bmp");
    QPixmap ele_1(":img/image/ele1.bmp");
    QPixmap ele_2(":img/image/ele2.bmp");
    QPixmap ele_3(":img/image/ele3.bmp");
    QPixmap ele_4(":img/image/ele4.bmp");
    QPixmap ele_5(":img/image/ele5.bmp");
    QPixmap ele_6(":img/image/ele6.bmp");
    QPixmap ele_7(":img/image/ele7.bmp");
    QPixmap ele_8(":img/image/ele8.bmp");
    QPixmap ele_9(":img/image/ele9.bmp");
    QPixmap blk_1(":img/image/blk1.bmp");
    QPixmap blk_2(":img/image/blk2.bmp");
    QPixmap blk_3(":img/image/blk3.bmp");
    QPixmap blk_4(":img/image/blk4.bmp");
    QPixmap blk_5(":img/image/blk5.bmp");
    QPixmap blk_6(":img/image/blk6.bmp");
    QPixmap blk_7(":img/image/blk7.bmp");
    QPixmap blk_8(":img/image/blk8.bmp");
    QPixmap mark(":img/image/unknown.bmp");
    if(paint_flag==0){
        paint_title(paint_my_window);
        for(int i=0;i<B->get_row()*BLOCK_LENGTH;i+=BLOCK_LENGTH){
            for(int j=TITLE_HEIGHT;j<B->get_col()*BLOCK_HEIGHT+TITLE_HEIGHT;j+=BLOCK_HEIGHT)
                painter.drawPixmap(i,j,block_close,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
        }
        paint_flag=1;
    }
    else{
        paint_title(paint_my_window);
        if(B->get_play()==true){
            for(int i=0;i<B->get_row();i++){
                for(int j=0;j<B->get_col();j++){
                    if(B->p[i][j].get_show()==false){
                        painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,block_close,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                    }
                    else{
                        if(B->p[i][j].get_mark()==true){
                            painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,mark,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        }
                        if(B->p[i][j].get_boom()==true){
                            painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,boom,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        }
                        else{
                            switch(B->p[i][j].get_sur())
                            {
                            case 0:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,block_open,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 1:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_1,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 2:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_2,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 3:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_3,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 4:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_4,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 5:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_5,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 6:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_6,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 7:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_7,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 8:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_8,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            }
                        }
                    }
                }
            }
        }
        else{
            if(B->get_win()==true){
                for(int i=0;i<B->get_row();i++)
                    for(int j=0;j<B->get_col();j++){
                        if(B->p[i][j].get_flag()==true)
                            painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,red_flag,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        else{
                            switch(B->p[i][j].get_sur())
                            {
                            case 0:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,block_open,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 1:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_1,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 2:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_2,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 3:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_3,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 4:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_4,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 5:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_5,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 6:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_6,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 7:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_7,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 8:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_8,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                        }
                    }
            }
        }
            else if(B->get_lose()==true){
                for(int i=0;i<B->get_row();i++)
                    for(int j=0;j<B->get_col();j++){
                        if(B->p[i][j].get_flag()==true)
                            painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,red_flag,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        else if(B->p[i][j].get_boom()==true){
                            painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,boom,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        }
                        else{
                            switch(B->p[i][j].get_sur())
                            {
                            case 0:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,block_open,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 1:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_1,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 2:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_2,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 3:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_3,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 4:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_4,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 5:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_5,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 6:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_6,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 7:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_7,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
                            case 8:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_8,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);break;
            }
        //painter.drawPixmap(click_x*BLOCK_LENGTH,click_y*BLOCK_HEIGHT+TITLE_HEIGHT,click_boom,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
    }
}
              painter.drawPixmap(click_x*BLOCK_LENGTH,click_y*BLOCK_HEIGHT+TITLE_HEIGHT,click_boom,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
            }
        }
    }
}

void MainWindow :: paint_title(QPainter  * painter)
{
    QPixmap restart(":img/image/smile.bmp");
    QPixmap mine_title(":img/image/mine_title.bmp");
    mine_title=mine_title.scaled(QSize(B->get_col()*21,40));
    painter->drawPixmap(0,23,restart,0,0,100,100);
    painter->drawPixmap(0,23,mine_title,0,0,1000,1000);
    painter->drawPixmap((int)B->get_col()*21*100/200-11,30,restart,0,0,1000,1000);
}

void MainWindow :: paint_boom(QPainter *painter)
{

}
void MainWindow ::mousePressEvent(QMouseEvent * event)
{
   click_x=event->x();
   click_y=event->y();
   if(false)
   //if(event->buttons()==(Qt::LeftButton)&&(click_x>0)&&(click_x<100)&&(click_y>0)&&(click_y<100)) LOTS OF PROBLEMS..
   {
       qDebug()<<"RESTART";
       std::any param1 (std::make_any<BlockParameter>());
       BlockParameter& ts= std::any_cast<BlockParameter&>(param1);
       ts.row = 7;
       ts.col = 7;
       ts.boom_num = 1;
       m_cmd_restart->SetParameter(param1);
       m_cmd_restart->Exec();
       //update();
   }
   if(event->buttons()==(Qt::LeftButton))
       if(click_x>0)
           if(click_x<B->get_col()*BLOCK_LENGTH)
               if(click_y>TITLE_HEIGHT)
                   if(click_y<B->get_row()*BLOCK_HEIGHT+TITLE_HEIGHT)
   {
       //qDebug()<<"left_button";
       std::any param2 (std::make_any<PosParameter>());
       PosParameter& pos= std::any_cast<PosParameter&>(param2);
       pos.j=click_x/BLOCK_LENGTH;
       pos.i=(click_y-TITLE_HEIGHT)/BLOCK_HEIGHT;
       m_cmd_left->SetParameter(param2);
       m_cmd_left->Exec();
   }
   if(event->buttons()==(Qt::RightButton)&&(click_x>0)&&(click_x<B->get_col()*BLOCK_LENGTH)&&(click_y>TITLE_HEIGHT)&&(click_y<B->get_row()*BLOCK_HEIGHT)){
       //qDebug()<<"right_button";
       std::any param3 (std::make_any<PosParameter>());
       PosParameter& pos= std::any_cast<PosParameter&>(param3);
       pos.j=click_x/BLOCK_LENGTH;
       pos.i=(click_y-TITLE_HEIGHT)/BLOCK_HEIGHT;
       m_cmd_left->SetParameter(param3);
       m_cmd_left->Exec();
   }
}

void MainWindow ::set_block(const std:: shared_ptr<Block> b)
{
    this->B=b;
}


