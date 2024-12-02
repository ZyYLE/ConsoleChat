#pragma once
#include <stdlib.h>     /* malloc, free */
#include "ChatMessage.h"
#include "ChatUser.h"


class MessageBase
{
protected:

    unsigned short _totalmsgs; // ����� ��������� � ����
    unsigned short _msgbasesize; // ������ ���� (�����������) 
    ChatMessage* _startmsgPtr = nullptr; // ��������� �� ������ ���������

public:

    MessageBase(unsigned short msgbasesize); //�������� ���� ������� �������

    virtual ~MessageBase();

    bool AddMsg(ChatMessage chatmsg); // ���������� ��������� � ����
    
    ChatMessage GetMsg(unsigned short msgindex); // ����������. ���������� ��������� �� ������ 

    void PrintAll(); // ���������� ���� ���������

    bool FindUserMsg(ChatUser* chatuser, MessageBase* dmb); // ������� ��������� ��� ����������� �����


};

