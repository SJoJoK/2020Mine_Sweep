QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app/msapp.cpp \
    common/block.cpp \
    common/parameter.cpp \
    common/square.cpp \
    main.cpp \
    model/msdatamodel.cpp \
    view/mainwindow.cpp \
    view/sink/mainwindowcommandsink.cpp \
    view/sink/mainwindowpropertysink.cpp \
    viewmodel/commands/leftblock.cpp \
    viewmodel/commands/rankaddcommand.cpp \
    viewmodel/commands/resetblockcommand.cpp \
    viewmodel/commands/restartcommand.cpp \
    viewmodel/commands/rightblockcommand.cpp \
    viewmodel/msviewmodel.cpp \
    viewmodel/sinks/msviewmodelsink.cpp

HEADERS += \
    app/msapp.h \
    common/block.h \
    common/etlbase.h \
    common/parameter.h \
    common/square.h \
    model/msdatamodel.h \
    view/mainwindow.h \
    view/sink/mainwindowcommandsink.h \
    view/sink/mainwindowpropertysink.h \
    viewmodel/commands/leftblock.h \
    viewmodel/commands/rankaddcommand.h \
    viewmodel/commands/resetblockcommand.h \
    viewmodel/commands/restartcommand.h \
    viewmodel/commands/rightblockcommand.h \
    viewmodel/msviewmodel.h \
    viewmodel/sinks/msviewmodelsink.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
