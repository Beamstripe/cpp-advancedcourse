#-------------------------------------------------
#
# Project created by QtCreator 2021-11-08T09:20:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dialog
TEMPLATE = app
CONFIG   += C++11

SOURCES += main.cpp\
        mainwindow.cpp \
    centerwidget.cpp

HEADERS  += mainwindow.h \
    centerwidget.h

FORMS    += mainwindow.ui
