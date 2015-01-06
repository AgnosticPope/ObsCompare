#ifndef OBSSTABILITYTEST_H
#define OBSSTABILITYTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <QtTest/QtTest>

class EmitterInterface;
class ReceiverInterface;

class ObserverUnitTest: public QObject
{
    Q_OBJECT
private slots:
    void init();
    void cleanup();

    void testEasy();
    void testObsDelete();
    void testRecDelete();
private:
    EmitterInterface* m_emitter;
    ReceiverInterface* m_receiver;
};

#endif // OBSSTABILITYTEST_H