#ifndef TRADCPPOBS_H
#define TRADCPPOBS_H
#include <vector>

#include "obsbase.h"

class TradReceiver :
        public ReceiverInterface
{
public:
  TradReceiver(int data) : ReceiverInterface(data) {}
  virtual ~TradReceiver() { }
  virtual void connect(EmitterInterface *eInt);

};


class TradEmitter : public EmitterInterface
{
public:
  TradEmitter() {}
  virtual void doEmit();
  void addObs(TradReceiver* );
private:
  std::vector<TradReceiver*> m_obs;
};



#endif // TRADCPPOBS_H
