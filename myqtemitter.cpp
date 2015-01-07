#include "myqtemitter.h"
#include <QDebug>
MyQtEmitter::MyQtEmitter() : QObject(), EmitterInterface()
{

}

MyQtEmitter::~MyQtEmitter()
{

}

void MyQtEmitter::doEmit()
{
    emit mySignal();
}



MyQtReceiver::MyQtReceiver(int data) : ReceiverInterface(data)
{

}

MyQtReceiver::~MyQtReceiver()
{

}

void MyQtReceiver::connect(EmitterInterface *e)
{
    MyQtEmitter* qe=dynamic_cast<MyQtEmitter*>(e);
    QObject::connect(qe,&MyQtEmitter::mySignal,
                    this,&MyQtReceiver::myReceive);

}

void MyQtReceiver::myReceive()
{
    // Base class
    OnReceive();
}
