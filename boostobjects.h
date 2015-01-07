#ifndef BOOSTOBJECTS_H
#define BOOSTOBJECTS_H

#include <boost/signals2.hpp>
#include <boost/signals2/trackable.hpp>
#include "obsbase.h"

class BoostEmitter : public EmitterInterface
{
public:
  virtual void doEmit();
  boost::signals2::signal<void ()> m_signal;
};

class BoostReceiver : public boost::signals2::trackable,
        public ReceiverInterface
{
public:
  BoostReceiver(int data) : ReceiverInterface(data) {}
  virtual ~BoostReceiver() { }
  virtual void connect(EmitterInterface *eInt);

};


#endif // BOOSTOBJECTS_H
