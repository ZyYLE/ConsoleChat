#pragma once

//#include <cstddef>
#include <stdlib.h>     /* malloc, free */
//#include <iostream>

#include "ChatUser.h"

class UserBase 
{
    protected:

        unsigned short _totalusers; // ����� ������ � ����
        unsigned short _userbasesize; // ������ ���� (�����������) 
        ChatUser* _startuserPtr = nullptr; // ��������� �� ������ ������

    public:
        
        UserBase(unsigned short userbasesize);
        
        virtual ~UserBase();
        
        //void Init();
        //bool Resize(unsigned short newsize);
        
        bool AddUser(ChatUser chatuser);
        
        //bool DelUser(ChatUser chatuser);

        //ChatUser&  GetUserList();

        bool CheckNick(std::string nickname);

        // ��� ����� ���-�� �������� ����� ����� �������� ��� � ���������?? 
        void ListUsers();
};

