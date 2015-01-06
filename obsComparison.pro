#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T09:43:02
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = obsComparison
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/
LIBS+= -L/usr/local/lib -lgtest

SOURCES += main.cpp \
    obsstabilitytest.cpp \
    boostobjects.cpp \
    myqtemitter.cpp

HEADERS += \
    obsbase.h \
    obsstabilitytest.h \
    boostobjects.h \
    myqtemitter.h
