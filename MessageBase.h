#pragma once
#include <stdlib.h>     /* malloc, free */
#include "ChatMessage.h"
#include "ChatUser.h"


class MessageBase
{
protected:

    unsigned short _totalmsgs; // всего сообщений в базе
    unsigned short _msgbasesize; // размер базы (вместимость) 
    ChatMessage* _startmsgPtr = nullptr; // указатель на массив сообщений

public:

    MessageBase(unsigned short msgbasesize); //создание базы нужного размера

    virtual ~MessageBase();

    bool AddMsg(ChatMessage chatmsg); // добавление сообщения в базу
    
    ChatMessage GetMsg(unsigned short msgindex); // отлажочная. распечатка сообщения по номеру 

    void PrintAll(); // распечатка всех сообщений

    bool FindUserMsg(ChatUser* chatuser, MessageBase* dmb); // выборка сообщений для конкретного юзера


};

