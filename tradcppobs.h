#ifndef TRADCPPOBS_H
#define TRADCPPOBS_H
#include <vector>

#include "obsbase.h"

class TradEmitter;

class TradReceiver :
        public ReceiverInterface
{
public:
  TradReceiver(int data) : ReceiverInterface(data), m_emit(NULL) {}
  virtual ~TradReceiver();
  virtual void connect(EmitterInterface *eInt);
  TradEmitter* m_emit;
};


class TradEmitter : public EmitterInterface
{
public:
  TradEmitter() {}
  virtual void doEmit();
  void addObs(TradReceiver* );
  void remObs(TradReceiver* );
private:
  std::vector<TradReceiver*> m_obs;
};



#endif // TRADCPPOBS_H
