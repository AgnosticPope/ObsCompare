#include <iostream>
#include "obsbase.h"

ReceiverInterface::ReceiverInterface(int data) : m_num(new int(3)) {}

ReceiverInterface::~ReceiverInterface()
{
    delete m_num;
    m_num=0;
}

void ReceiverInterface::OnReceive() {     std::clog << "Receiver: received signal " << *m_num <<std::endl; }
