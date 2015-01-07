#ifndef MYQTEMITTER_H
#define MYQTEMITTER_H

#include <QObject>
#include "obsbase.h"

class MyQtEmitter : public QObject, public EmitterInterface
{
    Q_OBJECT
public:
    MyQtEmitter();
    ~MyQtEmitter();
signals:
    void mySignal();
};

class MyQtReceiver : public QObject, public ReceiverInterface
{
    Q_OBJECT
public:
    MyQtReceiver(int data);
    ~MyQtReceiver();
    void connect(EmitterInterface* e);
public slots:
    void myReceive();
};

#endif // MYQTEMITTER_H
