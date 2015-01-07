#include "obsstabilitytest.h"
#include "myqtemitter.h"
#include "boostobjects.h"

#define TEST_EMITTER MyQtEmitter
#define TEST_RECEIVER MyQtReceiver

void ObserverUnitTest::init()
{
    m_emitter=new TEST_EMITTER();
    m_receiver=new TEST_RECEIVER(5);
}

void ObserverUnitTest::cleanup()
{
    qDebug()<<"Cleaning up";
    if (m_emitter) delete m_emitter;
    if (m_receiver) delete m_receiver;
    qDebug()<<"Done cleaning";
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
    delete m_receiver;
    m_receiver=NULL;

}

