TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
SOURCES += main.cpp \
    ticket.cpp \
    train.cpp \
    seat.cpp \
    ticketmanage.cpp \
    highspeedtrain.cpp \
    sleepertrain.cpp \
    standardtrain.cpp \
    function.cpp

HEADERS += \
    ticket.h \
    train.h \
    seat.h \
    ticketmanage.h \
    highspeedtrain.h \
    sleepertrain.h \
    standardtrain.h \
    function.h \
    headers.h

