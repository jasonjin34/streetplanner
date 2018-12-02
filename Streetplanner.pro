#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T15:28:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Streetplanner
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    city.cpp \
    map.cpp \
    abstractmap.cpp \
    street.cpp \
    dialog_addcity.cpp \
    mapio.cpp \
    mapionrw.cpp \
    dijkstra.cpp \
    mapiofileinput.cpp

HEADERS += \
        mainwindow.h \
    city.h \
    map.h \
    abstractmap.h \
    abstractmap.h \
    street.h \
    dialog_addcity.h \
    mapio.h \
    mapionrw.h \
    dijkstra.h \
    mapiofileinput.h

FORMS += \
        mainwindow.ui \
    dialog_addcity.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
