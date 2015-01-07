#include "tradcppobs.h"
#include <iostream>

void TradEmitter::doEmit()
{
    std::clog << "Emitter: emitting signal\n";
    for(unsigned int i=0; i < m_obs.size(); i++)
    {
        m_obs[i]->OnReceive();
    }
}

void TradEmitter::addObs(TradReceiver *r)
{
    m_obs.push_back(r);
}

void TradReceiver::connect(EmitterInterface *eInt)
{
    TradEmitter* e=dynamic_cast<TradEmitter*>(eInt);
    if (!e)
    {
        return;
    }
    e->addObs(this);
}
