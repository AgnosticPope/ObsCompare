#-------------------------------------------------
# Project created by QtCreator 2015-01-06T09:43:02
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/
LIBS+= -L/usr/local/lib

SOURCES += main.cpp \
    obsstabilitytest.cpp \
    boostobjects.cpp \
    myqtemitter.cpp \
    obsbase.cc \
    tradcppobs.cpp

HEADERS += \
    obsbase.h \
    obsstabilitytest.h \
    boostobjects.h \
    myqtemitter.h \
    tradcppobs.h

configQtEmitter {
TARGET = qtEmit
DEFINES += QT_EMITTER_TEST
}

configBoostEmitter {
  TARGET = boostEmit
  DEFINES += BOOST_EMITTER_TEST
}

configTradEmitter {
  TARGET = tradEmit
#  DEFINES += BOOST_EMITTER_TEST
}


#QMAKE_CXXFLAGS_WARN_ON = -Wno-unused-variable -Wno-reorder
