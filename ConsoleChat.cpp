

#include <iostream>
#include <windows.h>
#include "UserBase.h"
#include "MessageBase.h"


int main()
{
   

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода


   
    UserBase ub1(3);

    ChatUser ct1("User one", "pass1", 7, 12);
    ub1.AddUser(ct1);

    ub1.ListUsers();


    MessageBase mb1(3);

    ChatMessage ctm("Первое сообщение", "12-00", 0, 1, 2);
    bool b=mb1.AddMsg(ctm);
    
    for (int ix = 0; ix < 5; ix++)
    {
        ctm.SetMsgBody(("сообщение " + std::to_string(ix)));
        mb1.AddMsg(ctm);

    }
    
    for (int ix = 0; ix < 5; ix++)
    {
        (mb1.GetMsg(ix)).PrintMsg();

                
    }

    std::cout << (mb1.GetMsg(4)).GetMsgBody() << std::endl;









}

