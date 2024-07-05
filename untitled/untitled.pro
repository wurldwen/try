QT        += core gui #multimedia
#QT       +=直接加在第一行
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosetheme.cpp \
    coin.cpp \
    data.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    playscene.cpp

HEADERS += \
    choosetheme.h \
    coin.h \
    data.h \
    mainwindow.h \
    mypushbutton.h \
    playscene.h

FORMS += \
    mainwindow.ui

#RC_ICONS=ys.ico;
#RC_FILE += ys.rc   //你的资源文件名

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    ys.ico

RC_ICONS+= ys.ico
