#ifndef BOOSTOBJECTS_H
#define BOOSTOBJECTS_H

//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wunused-variable"
#include <boost/signals2.hpp>
#include <boost/signals2/trackable.hpp>
//#pragma clang diagnostic pop
#include "obsbase.h"

// These classes use the boost library to connect different objects
// Notes on the Emitter:
// * Resturn type and arguments for the function is listed in the template argument.
class BoostEmitter : public EmitterInterface
{
public:
  virtual void doEmit();
  boost::signals2::signal<void ()> m_signal;
};

// This is the receiver object for Boost
// Important notes:
// * Inheriting from boost::trackable is strongly advised! Otherwise you will fail
//    the all unit tests after the first!  In real life, this results in odd crashes.
class BoostReceiver : public boost::signals2::trackable,
        public ReceiverInterface
{
public:
  BoostReceiver(int data) : ReceiverInterface(data) {}
  virtual void connect(EmitterInterface *eInt);

};

#endif // BOOSTOBJECTS_H
