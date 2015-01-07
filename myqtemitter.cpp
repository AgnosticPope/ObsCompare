#include "myqtemitter.h"

MyQtEmitter::MyQtEmitter()
{

}

MyQtEmitter::~MyQtEmitter()
{

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
    QObject::connect(qe,SIGNAL(mySignal()),
            SLOT(myReceive()));

}

void MyQtReceiver::myReceive()
{

}
