#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T11:08:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    block.cpp \
    Destroy.cpp \
    for3.cpp \
    for4.cpp \
    for5.cpp \
    forvertical.cpp \
    forhori.cpp \
    fornine.cpp \
    forlort.cpp \
    win.cpp

HEADERS  += game.h \
    block.h \
    Destroy.h \
    for3.h \
    for4.h \
    for5.h \
    forvertical.h \
    forhori.h \
    fornine.h \
    forlort.h \
    win.h

FORMS    += game.ui \
    win.ui

RESOURCES += \
    pic.qrc \
    win.qrc
