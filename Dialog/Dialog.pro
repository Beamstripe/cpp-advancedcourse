#-------------------------------------------------
#
# Project created by QtCreator 2021-11-08T09:20:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dialog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    centerwidget.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    centerwidget.h

FORMS    += mainwindow.ui
