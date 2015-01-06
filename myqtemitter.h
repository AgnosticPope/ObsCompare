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
};

class MyQtReceiver : public QObject, public ReceiverInterface
{
    Q_OBJECT
public:
    MyQtReceiver();
    ~MyQtReceiver();
};

#endif // MYQTEMITTER_H
