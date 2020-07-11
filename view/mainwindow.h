#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include"../common/etlbase.h"
#include"sink/mainwindowcommandsink.h"
#include"sink/mainwindowpropertysink.h"
#include"../viewmodel/msviewmodel.h"
#include"common/parameter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_restart_command(const std::shared_ptr<ICommandBase>& cmd) throw();
    void set_leftblock_command(const std::shared_ptr<ICommandBase>& cmd) throw();
    void set_restart_num(const int num) throw();
    void set_block(const std:: shared_ptr<Block> b);
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
    std::shared_ptr<ICommandNotification> get_command_sink() throw();
    std::shared_ptr<MSViewModel> m_pVM;
    void paint_restart_num();
    void paint_title(QPainter  * painter);
    void paint_boom(QPainter * painter);
    void init();
protected:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
private:
    Ui::MainWindow *ui;
    int click_x,click_y;
    std::shared_ptr<ICommandBase> m_cmd_restart;
    std::shared_ptr<ICommandBase> m_cmd_left;
    std::shared_ptr<MainWindowPropertySink> m_sink_property;
    std::shared_ptr<MainWindowCommandSink> m_sink_command;
    std::shared_ptr<Block> B;

};
#endif // MAINWINDOW_H
