#pragma once

//#include <cstddef>
#include <stdlib.h>     /* malloc, free */
//#include <iostream>

#include "ChatUser.h"

class UserBase 
{
    protected:

        unsigned short _totalusers; // всего юзеров в базе
        unsigned short _userbasesize; // размер базы (вместимость) 
        ChatUser* _startuserPtr = nullptr; // указатель на массив юзеров

    public:
        
        UserBase(unsigned short userbasesize);
        
        virtual ~UserBase();
        
        //void Init();
        //bool Resize(unsigned short newsize);
        
        bool AddUser(ChatUser chatuser);
        
        //bool DelUser(ChatUser chatuser);

        //ChatUser&  GetUserList();

        bool CheckNick(std::string nickname);

        // еще нужно как-то забирать юзера чтобы пописать его в сообщении?? 
        void ListUsers();
};

