#include "myqtemitter.h"

MyQtEmitter::MyQtEmitter()
{

}

MyQtEmitter::~MyQtEmitter()
{

}



MyQtReceiver::MyQtReceiver()
{

}

MyQtReceiver::~MyQtReceiver()
{

}

void MyQtReceiver::connect(EmitterInterface *e)
{
    MyQtEmitter* qe=dynamic_cast<MyQtEmitter*>(e);
    connect(qe,SIGNAL(mySignal()),
            this,SLOT(myReceive()));

}

void MyQtReceiver::myReceive()
{

}
