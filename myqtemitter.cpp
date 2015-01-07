#include "myqtemitter.h"
#include <QDebug>


void MyQtEmitter::doEmit()
{
    emit mySignal();
}

void MyQtReceiver::connect(EmitterInterface *e)
{
    MyQtEmitter* qe=dynamic_cast<MyQtEmitter*>(e);
    if (!e) return;

    QObject::connect(qe,&MyQtEmitter::mySignal,
                    this,&MyQtReceiver::myReceive);

}
