#-------------------------------------------------
#
# Project created by QtCreator 2021-12-28T19:39:11
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

CONFIG += C++11

HEADERS  += mainwindow.h \
    leftwidget.h \
    rightwidget.h \
    ball.h \
    paintlabel.h
