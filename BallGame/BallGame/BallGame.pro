#-------------------------------------------------
#
# Project created by QtCreator 2021-11-24T08:53:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BallGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    leftwidget.cpp \
    rightwidget.cpp \
    ball.cpp \
    paintlabel.cpp

HEADERS  += mainwindow.h \
    leftwidget.h \
    rightwidget.h \
    ball.h \
    paintlabel.h
