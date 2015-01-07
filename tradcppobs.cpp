#include "tradcppobs.h"
#include <iostream>

TradEmitter::~TradEmitter()
{
    foreach(TradReceiver* r, m_obs)
    {
        r->observe(NULL);
    }
}

void TradEmitter::doEmit()
{
    std::clog << "Emitter: emitting signal\n";
    foreach(TradReceiver* r, m_obs)
    {
        r->OnReceive();
    }

}

void TradEmitter::addObs(TradReceiver *r)
{
    m_obs.insert(r);
}

void TradEmitter::remObs(TradReceiver *r)
{
    m_obs.remove(r);
}

TradReceiver::~TradReceiver()
{
    if (m_emit)
        m_emit->remObs(this);
}

void TradReceiver::connect(EmitterInterface *eInt)
{
    observe(dynamic_cast<TradEmitter*>(eInt));
}

void TradReceiver::observe(TradEmitter *e)
{
    if (m_emit)
        m_emit->remObs(this);
    m_emit=e;
    if (!m_emit)
    {
        return;
    }
    m_emit->addObs(this);
}
