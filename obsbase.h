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
    ReceiverInterface(int data);
    virtual ~ReceiverInterface();
    virtual void connect(EmitterInterface* e)=0;
    int* m_num;

    virtual void OnReceive();

};

#endif // OBSBASE

