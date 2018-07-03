#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T21:34:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPEResolver
TEMPLATE = app


SOURCES += main.cpp\
        uidisplay.cpp \
    generator.cpp \
    minesweeper.cpp

HEADERS  += uidisplay.h \
    generator.h \
    minesweeper.h

FORMS    += uidisplay.ui
