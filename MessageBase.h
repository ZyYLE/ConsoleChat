#pragma once
#include <stdlib.h>     /* malloc, free */
#include "ChatMessage.h"


class MessageBase
{
protected:

    unsigned short _totalmsgs; // всего сообщений в базе
    unsigned short _msgbasesize; // размер базы (вместимость) 
    ChatMessage* _startmsgPtr = nullptr; // указатель на массив сообщений

public:

    MessageBase(unsigned short msgbasesize);

    virtual ~MessageBase();

    bool AddMsg(ChatMessage chatmsg);
    
    ChatMessage GetMsg(unsigned short msgindex);


};

