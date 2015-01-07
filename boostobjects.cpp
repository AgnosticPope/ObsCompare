#include "boostobjects.h"

#include <iostream>

void BoostEmitter::doEmit()
{
    m_signal();
}

void BoostReceiver::connect(EmitterInterface *eInt)
{
    BoostEmitter* e=dynamic_cast<BoostEmitter*>(eInt);
    if (!e)
    {
        assert(e);
        return;
    }
    e->m_signal.connect(
      boost::bind(
        &BoostReceiver::OnReceive,
        this));  //Let emitter emit its signal
}
