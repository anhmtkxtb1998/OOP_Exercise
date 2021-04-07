QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    computer.cpp \
    controlwindow.cpp \
    interface.cpp \
    main.cpp \
    model.cpp \
    paramwindow.cpp \
    statewindow.cpp

HEADERS += \
    application.h \
    computer.h \
    controlwindow.h \
    eventypes.h \
    interface.h \
    model.h \
    paramdata.h \
    paramwindow.h \
    statedata.h \
    statewindow.h

FORMS += \
    controlwindow.ui \
    interface.ui \
    paramwindow.ui \
    statewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
