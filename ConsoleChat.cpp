

#include <iostream>
#include <windows.h>
#include "UserBase.h"
#include "MessageBase.h"
#include "ChatDisplay.h"

int main()
{


	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода



	UserBase ub1(3); //инициализируем БД пользователей

	ChatUser ct1("User_one", "pass1", "full name", 1, 0);  //Временный юзер 1 отправитель
	ChatUser ct2("User_one", "pass1", "full name", 1, 0);  //Временный юзер 2 получатель

	
	//ub1.AddUser(&ct1);

	ub1.ListUsers(); // вывод списка пользователей


	 MessageBase mb1(3); // инициализируем базу сообщений

	 //ChatMessage ctm("Первое сообщение", "12-00", 0, 1, 2); // отладочное сообщение
	 //bool b=mb1.AddMsg(ctm);



	std::string ls; //login
	std::string ps; //pass
	std::string fn; //full name
	std::string ms; //message

	bool userlogged = 0;
	
	ChatDisplay  chatdisplay1; // класс где живут все диалоги
	
	while (true)
	{



		bool logoffselected = 0;
		while (!logoffselected)
		{

			while (!userlogged)
			{
				chatdisplay1.ShowWelcome();

				unsigned short loginmenuresult = chatdisplay1.LoginMenu();

				if (loginmenuresult == 1) // выбрали залогиниться (ввести логин)
				{

					unsigned short askloginmenuresult = 100;

					while (askloginmenuresult)
					{
						askloginmenuresult = chatdisplay1.AskLogin(askloginmenuresult, &ls, &ps);//запросили ввод логина и пароля

						//проверяем есть ли юзер и его ли это пароль
						ct1.SetUsername(ls);
						ct1.SetUserpass(ps);
						userlogged = 1;

						if (!(ub1.CheckLogin(&ct1)))
						{

							if (chatdisplay1.RetryMenu()) askloginmenuresult = 100;
							userlogged = 0;
						}

					}

				};

				if (loginmenuresult == 2) // выбрали зарегистрироваться
				{
					unsigned short askloginmenuresult = 100;

					while (askloginmenuresult)
					{
						askloginmenuresult = chatdisplay1.AskRegister(askloginmenuresult, &ls, &ps, &fn);//запросили ввод логина и пароля

						//проверяем есть ли юзер и его ли это пароль
						ct1.SetUsername(ls);
						ct1.SetUserpass(ps);
						ct1.SetUserfullname(fn);
						userlogged = 1;

						if (ub1.CheckNick(&ct1))
						{

							if (chatdisplay1.RetryMenu()) askloginmenuresult = 100;
							userlogged = 0;
						}

					}

					if (userlogged)
					{
						ub1.AddUser(&ct1);
					};


				};



			}

			// в этой точке есть залогиненый юзер ct1
			// здесь нужно меню сенд-ресив и логоф
			unsigned short sendrecievelogoff = chatdisplay1.SendRecieveLogoff();
					
			if (sendrecievelogoff == 3) // выбран логоф
			{
				logoffselected = 1;
				userlogged = 0;
			}

			if (sendrecievelogoff == 1) // выбран Отправка сообщения
			{
				// отправка сообщения
				ub1.ListUsers();
				
				unsigned short sendmenuresult = 0;
				bool correctuser = 0;

				while (!sendmenuresult)
				{
					sendmenuresult = chatdisplay1.SendMenu(&ls, &ms);

					//проверяем есть ли юзер 
					ct2.SetUsername(ls);
					ct2.SetUserID(0); //если получатель найдется, то id  перепишется из получателя
										
					if ((!(ub1.CheckNick(&ct2)))&&(ls!="*"))  //если юзера с ником нет и ник не *, то спрашиваем о повторе
					{

						if (chatdisplay1.RetryMenu()) sendmenuresult =0;
						
					}
					else
					{
						correctuser = 1;
					}
				}

				// если correctuser то можно отправлять. в ct2 лежит адресат либо адресаты все. 

				//формируем сообщение 
				ChatMessage ctm(ms, " ", 0, ct1.GetUserID(), ct2.GetUserID());
				
				//добавляем сообщение в базу сообщений
				mb1.AddMsg(ctm);
				ctm.PrintMsg();

			}

			if (sendrecievelogoff == 2) // выбран Получение  сообщений
			{
				// Получение  сообщений
				mb1.PrintAll(); //отладка - печать всех сообщений
				std::cout << "Теперь нужные:" << std::endl;

				MessageBase mb2(5); // временная база для принятия сообщений текущего юзера
				mb1.FindUserMsg(&ct1, &mb2);
				mb2.PrintAll();

			}


		}

	}

	ub1.ListUsers();






}


