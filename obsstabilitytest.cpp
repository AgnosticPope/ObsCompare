#include "obsstabilitytest.h"

#include "boostobjects.h"

void ObserverUnitTest::init()
{
    m_emitter=new BoostEmitter();
    m_receiver=new BoostReceiver(5);
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
