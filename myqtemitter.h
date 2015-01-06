#ifndef MYQTEMITTER_H
#define MYQTEMITTER_H

#include <QObject>
#include "obsbase.h"

class MyQtEmitter : public QObject
{
    Q_OBJECT
public:
    MyQtEmitter();
    ~MyQtEmitter();
};

class MyQtReceiver : public ReceiverInterface, public QObject
{
    Q_OBJECT
public:
    MyQtReceiver();
    ~MyQtReceiver();
};

#endif // MYQTEMITTER_H
