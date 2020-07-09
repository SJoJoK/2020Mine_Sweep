#include "mainwindow.h"
#include "ui_mainwindow.h"
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
       qDebug()<<"RESTART";
       std::any param (std::make_any<BlockParameter>());
       BlockParameter& ts= std::any_cast<BlockParameter&>(param);
       ts.row = 3;
       ts.col = 2;
       ts.boom_num = 1;
       m_cmd_restart->SetParameter(param);
       m_cmd_restart->Exec();
       //update();
   }

}

