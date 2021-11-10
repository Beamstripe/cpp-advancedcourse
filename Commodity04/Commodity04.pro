#-------------------------------------------------
#
# Project created by QtCreator 2021-11-04T23:14:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Commodity04
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Commodity.cpp \
    NormalCommodity.cpp \
    OverseaCommodity.cpp \
    commodityManage.cpp \
    function.cpp

HEADERS += \
    Commodity.h \
    NormalCommodity.h \
    OverseaCommodity.h \
    commodityManage.h \
    function.h \
    header.h
