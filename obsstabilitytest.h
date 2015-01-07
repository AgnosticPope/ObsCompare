#ifndef OBSSTABILITYTEST_H
#define OBSSTABILITYTEST_H

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
    void testMultiObs();
private:
    EmitterInterface* m_emitter;
    ReceiverInterface* m_receiver;
};

#endif // OBSSTABILITYTEST_H
