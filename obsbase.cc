#include <iostream>
#include "obsbase.h"

ReceiverInterface::ReceiverInterface(int data) : m_num(new int(data)) {}

ReceiverInterface::~ReceiverInterface()
{
    delete m_num;
    m_num=0;
}

void ReceiverInterface::OnReceive()
{
    (*m_num)++;
}
