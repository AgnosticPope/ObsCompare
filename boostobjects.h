#ifndef BOOSTOBJECTS_H
#define BOOSTOBJECTS_H

#include <boost/signals2.hpp>
#include <boost/signals2/trackable.hpp>
#include "obsbase.h"

// These classes use the boost library to connect different objects
class BoostEmitter : public EmitterInterface
{
public:
  virtual void doEmit();
  boost::signals2::signal<void ()> m_signal;
};

// This is the receiver object for Boost
// Important notes:
// * Inheriting from boost::trackable is strongly advised! Otherwise you will fail
//    the all unit tests after the first!
class BoostReceiver : public boost::signals2::trackable,
        public ReceiverInterface
{
public:
  BoostReceiver(int data) : ReceiverInterface(data) {}
  virtual void connect(EmitterInterface *eInt);

};


#endif // BOOSTOBJECTS_H
