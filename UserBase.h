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
             
        bool AddUser(ChatUser* chatuser);// добавление юзера в базу
        
        bool CheckNick(ChatUser* chatuser); //проверка свободен ли логин при регистрации
        
        void ListUsers();// выводсписка юзеров

        bool CheckLogin(ChatUser* chatuser); // проверка совпадения логина и пароля при входе

};

