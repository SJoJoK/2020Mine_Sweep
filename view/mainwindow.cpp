#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sink_property(std::make_shared<MainWindowPropertySink>(this))
    , m_sink_command(std::make_shared<MainWindowCommandSink>(this))
{
    ui->setupUi(this);
    /*
    QPixmap mine_title(":/mine_title.bmp");
    QPixmap block_close(":/block_close.bmp");
    QPixmap block_open(":/block_open.bmp");
    QPixmap red_flag(":/redflag.bmp");
    QPixmap keil_boom(":/keilboom.bmp");
    QPixmap click_boom(":/clickboom.bmp");
    QPixmap boom(":/boom.bmp");
    QPixmap smile(":/smile.bmp");
    QPixmap lose(":/lose.bmp");
    QPixmap pround(":/pround.bmp");
    QPixmap ele_0(":/ele0.bmp");
    QPixmap ele_1(":/ele1.bmp");
    QPixmap ele_2(":/ele2.bmp");
    QPixmap ele_3(":/ele3.bmp");
    QPixmap ele_4(":/ele4.bmp");
    QPixmap ele_5(":/ele5.bmp");
    QPixmap ele_6(":/ele6.bmp");
    QPixmap ele_7(":/ele7.bmp");
    QPixmap ele_8(":/ele8.bmp");
    QPixmap ele_9(":/ele9.bmp");
    QPixmap ele_10(":/ele10.bmp");
    QPixmap blk_1(":/blk1.bmp");
    QPixmap blk_2(":/blk2.bmp");
    QPixmap blk_3(":/blk3.bmp");
    QPixmap blk_4(":/blk4.bmp");
    QPixmap blk_5(":/blk5.bmp");
    QPixmap blk_6(":/blk6.bmp");
    QPixmap blk_7(":/blk7.bmp");
    QPixmap blk_8(":/blk8.bmp");
    for(int i=0;i<now_block->get_col()*BLOCK_LENGTH;i+=BLOCK_LENGTH){
        for(int j=63;j<63+now_block->get_row()*BLOCK_HEIGHT;j+=BLOCK_HEIGHT)
            painter.drawPixmap(i,j,block_close,0,0,BLOCK_LENGTH,BLOCK_LENGTH);
    }
   */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint_restart_num()
{
    ui->RE_label->setText(QString::number(m_pVM->get_restart_num()));
}
void MainWindow::set_restart_command(const std::shared_ptr<ICommandBase> &cmd) throw()
{
     m_cmd_restart = cmd;
}

void MainWindow::set_restart_num(const int num) throw()
{
   ui->RE_label->setText(QString::number(num));
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
    painttitle(&painter);
}

void MainWindow :: painttitle(QPainter  * painter)
{
    QPixmap restart("C:/Users/tim/Desktop/restart.jpg");
    painter->drawPixmap(100,100,restart,0,0,1000,1000);
}
void MainWindow ::mousePressEvent(QMouseEvent * event)
{
   click_x=event->x();
   click_y=event->y();
   if(event->buttons()==(Qt::LeftButton))
   {
       qDebug()<<"点击重启";
       std::any param("restart");
       m_cmd_restart->SetParameter(param);
       m_cmd_restart->Exec();
       //update();
   }

}

