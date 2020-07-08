#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMainWindow>
#include <QDebug>
#include"../common/etlbase.h"
#include"sink/mainwindowcommandsink.h"
#include"sink/mainwindowpropertysink.h"
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
    std::shared_ptr<IPropertyNotification> get_propertty_sink() throw();
    std::shared_ptr<ICommandNotification> get_command_sink() throw();
    void paint_restart_num(int restart_num);
protected:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
private:
    Ui::MainWindow *ui;
    int click_x,click_y;
    std::shared_ptr<ICommandBase> m_cmd_restart;
    std::shared_ptr<MainWindowPropertySink> m_sink_property;
    std::shared_ptr<MainWindowCommandSink> m_sink_command;
};
#endif // MAINWINDOW_H