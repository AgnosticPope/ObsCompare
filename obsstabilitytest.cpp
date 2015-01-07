#include "obsstabilitytest.h"
#include "myqtemitter.h"
#include "boostobjects.h"
#include "tradcppobs.h"

#if 1
#define TEST_EMITTER MyQtEmitter
#define TEST_RECEIVER MyQtReceiver
#else
//#define TEST_EMITTER TradEmitter
//#define TEST_RECEIVER TradReceiver

#define TEST_EMITTER BoostEmitter
#define TEST_RECEIVER BoostReceiver
#endif


void ObserverUnitTest::init()
{
    m_emitter=new TEST_EMITTER();
    m_receiver=new TEST_RECEIVER(5);
}

void ObserverUnitTest::cleanup()
{
    if (m_emitter) delete m_emitter;
    if (m_receiver) delete m_receiver;
}

void ObserverUnitTest::testEasy()
{
    m_receiver->connect(m_emitter);
    m_emitter->doEmit();
}

void ObserverUnitTest::testObsDelete()
{
    m_receiver->connect(m_emitter);
    m_emitter->doEmit();
    QCOMPARE(m_receiver->data(),6);
    delete m_receiver;
    m_receiver=NULL;
    m_emitter->doEmit();
}

void ObserverUnitTest::testRecDelete()
{
    m_receiver->connect(m_emitter);
    m_emitter->doEmit();
    delete m_emitter;
    m_emitter=NULL;
    QCOMPARE(m_receiver->data(),6);
    delete m_receiver;
    m_receiver=NULL;

}

void ObserverUnitTest::testMultiObs()
{
    ReceiverInterface* sReceive=new TEST_RECEIVER(2);
    sReceive->connect(m_emitter);
    m_emitter->doEmit();
    QCOMPARE(sReceive->data(),3);
    m_receiver->connect(m_emitter);
    m_emitter->doEmit();
    QCOMPARE(sReceive->data(),4);
    QCOMPARE(m_receiver->data(),6);
    delete sReceive;
    m_emitter->doEmit();
    delete m_emitter;
    m_emitter=NULL;
}

