#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T13:56:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPEDemineur
TEMPLATE = app


SOURCES += main.cpp\
        uidisplay.cpp \
    minesweeper.cpp \
    generator.cpp

HEADERS  += uidisplay.h \
    minesweeper.h \
    generator.h

FORMS    += uidisplay.ui
