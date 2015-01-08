#ifndef MYQTEMITTER_H
#define MYQTEMITTER_H

#include <QObject>
#include "obsbase.h"

// These classes use the Qt library to connect different objects
class MyQtEmitter : public QObject, public EmitterInterface
{
    Q_OBJECT
public:
    virtual void doEmit();
signals:
    void mySignal();
};

// This is the receiver object for Qt
// Important notes:
//    * Failing to inherit from QObject or using the Q_OBJECT macro
//      will result in a compile time error.
//    * Any C++ Function can be a slot, but must be declared as such
//      to be used as such
class MyQtReceiver : public QObject, public ReceiverInterface
{
    Q_OBJECT
public:
    MyQtReceiver(int data) : ReceiverInterface(data) {}
    virtual void connect(EmitterInterface* e);
public slots:
    void myReceive() { OnReceive(); }
};

#endif // MYQTEMITTER_H
