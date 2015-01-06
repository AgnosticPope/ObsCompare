#ifndef OBSBASE
#define OBSBASE

class EmitterInterface
{
public:
    virtual ~EmitterInterface() {}
    virtual void doEmit()=0;
};

class ReceiverInterface
{
public:
    virtual ~ReceiverInterface() {}
    virtual void connect(EmitterInterface* e)=0;
};

#endif // OBSBASE

