#include "mainwindow.h"
#include "ui_mainwindow.h"
static int paint_flag=0;
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
         QPixmap mine_title("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/mine_title.bmp");
         QPixmap block_close("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/block_close.bmp");
         QPixmap block_open("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/block_open.bmp");
         QPixmap red_flag("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/redflag.bmp");
         QPixmap keil_boom("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/keilboom.bmp");
         QPixmap click_boom("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/clickboom.bmp");
         QPixmap boom("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/boom.bmp");
         QPixmap qq_smile("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/smile.bmp");
         QPixmap qq_lose("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/lose.bmp");
         QPixmap qq_pround("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/proud.bmp");
         QPixmap ele_0("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele0.bmp");
         QPixmap ele_1("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele1.bmp");
         QPixmap ele_2("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele2.bmp");
         QPixmap ele_3("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele3.bmp");
         QPixmap ele_4("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele4.bmp");
         QPixmap ele_5("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele5.bmp");
         QPixmap ele_6("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele6.bmp");
         QPixmap ele_7("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele7.bmp");
         QPixmap ele_8("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele8.bmp");
         QPixmap ele_9("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/ele9.bmp");
         QPixmap blk_1("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk1.bmp");
         QPixmap blk_2("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk2.bmp");
         QPixmap blk_3("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk3.bmp");
         QPixmap blk_4("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk4.bmp");
         QPixmap blk_5("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk5.bmp");
         QPixmap blk_6("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk6.bmp");
         QPixmap blk_7("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk7.bmp");
         QPixmap blk_8("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/blk8.bmp");
         QPixmap mark("C:/Users/tim/Desktop/2020Mine_Sweep-test/image/unknown.bmp");
    if(paint_flag==0){
        paint_title(paint_my_window);
        for(int i=0;i<B->get_row()*BLOCK_LENGTH;i+=BLOCK_LENGTH){
            for(int j=TITLE_HEIGHT;j<B->get_col()*BLOCK_HEIGHT+TITLE_HEIGHT;j+=BLOCK_HEIGHT)
                painter.drawPixmap(j,i,block_close,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
        }
    }
    else if(paint_flag==4){
        paint_title(paint_my_window);
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
                        case 0:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,block_open,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 1:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_1,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 2:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_2,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 3:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_3,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 4:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_4,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 5:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_5,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 6:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_6,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 7:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_7,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        case 8:painter.drawPixmap(j*BLOCK_LENGTH,i*BLOCK_HEIGHT+TITLE_HEIGHT,blk_8,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
                        }
                    }
                }
            }
        }
        painter.drawPixmap(click_x*BLOCK_LENGTH,click_y*BLOCK_HEIGHT+TITLE_HEIGHT,click_boom,0,0,BLOCK_LENGTH,BLOCK_HEIGHT);
    }
   else if(paint_flag==2){
        paint_title(paint_my_window);
        paint_boom(paint_my_window);
    }
   else if(paint_flag==3){
        paint_title(paint_my_window);
        paint_boom(paint_my_window);
    }
    else if(paint_flag==5){
        paint_title(paint_my_window);
        paint_boom(paint_my_window);
    }
}

void MainWindow :: paint_title(QPainter  * painter)
{
    QPixmap restart("F:/Homework/ShortSemester2/build-Mine_sweeping-Desktop_Qt_5_14_2_MSVC2017_64bit-Debug/smile.bmp");
    painter->drawPixmap(0,0,restart,0,0,100,100);
}

void MainWindow :: paint_boom(QPainter *painter)
{

>>>>>>> view
}
void MainWindow ::mousePressEvent(QMouseEvent * event)
{
   click_x=event->x();
   click_y=event->y();
   if(event->buttons()==(Qt::LeftButton)&&(click_x>0)&&(click_x<100)&&(click_y>0)&&(click_y<100))
   {
       qDebug()<<"RESTART";
       std::any param1 (std::make_any<BlockParameter>());
       BlockParameter& ts= std::any_cast<BlockParameter&>(param1);
       ts.row = 3;
       ts.col = 2;
       ts.boom_num = 1;
       m_cmd_restart->SetParameter(param1);
       m_cmd_restart->Exec();
       //update();
   }
   if(event->buttons()==(Qt::LeftButton)){
       qDebug()<<"left_button";
       std::any param2 (std::make_any<PosParameter>());
       PosParameter& pos= std::any_cast<PosParameter&>(param2);
       pos.i=click_x/BLOCK_LENGTH;
       pos.j=(click_y-TITLE_HEIGHT)/BLOCK_HEIGHT;
       m_cmd_left_click->SetParameter(param2);
       m_cmd_left_click->Exec();
   }
}

void MainWindow ::set_block(const std:: shared_ptr<Block> b)
{
    this->B=b;
}


