#ifndef TRADCPPOBS_H
#define TRADCPPOBS_H

#include <QSet>
#include "obsbase.h"

class TradEmitter;

class TradReceiver :
        public ReceiverInterface
{
public:
  TradReceiver(int data) : ReceiverInterface(data), m_emit(0) {}
  virtual ~TradReceiver();
  virtual void connect(EmitterInterface *eInt);
  void observe(TradEmitter* );
  TradEmitter* m_emit;
};


class TradEmitter : public EmitterInterface
{
public:
  TradEmitter() {}
  ~TradEmitter();
  virtual void doEmit();
  void addObs(TradReceiver* r);
  void remObs(TradReceiver* r);
private:
  QSet<TradReceiver*> m_obs;
};



#endif // TRADCPPOBS_H
