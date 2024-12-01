#include "ChatDisplay.h"

void ChatDisplay::ShowWelcome()
{
	std::cout << "Консольный чат - Велькам скрин" << std::endl;
}

unsigned short ChatDisplay::LoginMenu()
{
	std::cout << "Консольный чат - Логин/Регистрация" << std::endl;
	bool menudone = false;
	unsigned short userchoice=0;
	char uc;
	
	while (!menudone)
	{
		std::cout << "Выберите действие:" << std::endl;
		std::cout << "1. Ввести логин и пароль" << std::endl;
		std::cout << "2. Зарегистрироваться" << std::endl;
		std::cout << "Ввеедите номер:" << std::endl;
		std::cin >> uc;
		std::cin.sync();

		if (uc == '1')
		{
			userchoice = 1;
			menudone = 1;
		};
	
		if (uc == '2')
		{
			userchoice = 2;
			menudone = 1;
		}
	
			

	}

	
	return userchoice;
}

unsigned short ChatDisplay::RegisterMenu(char mm, std::string* login, std::string* pass)
{
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc;

	std::cout << "Консольный чат - Регистрация" << std::endl;
	
	if (mm == '1') std::cout << "Такой пользователь уже есть" << std::endl;
	if (mm == '2') std::cout << "Некорректный ввод" << std::endl;

	std::cout << "Введите логин:" << std::endl;
		
	std::cin >> *login;
	std::cin.sync();

	std::cout << "Введите пароль:" << std::endl;

	std::cin >> *pass;
	std::cin.sync();

	return 0;
}

unsigned short ChatDisplay::AskLogin(char mm, std::string* login, std::string* pass)
{
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc;

	std::cout << "Консольный чат - Вход" << std::endl;

	if (mm == '1') std::cout << "Неверный логин или пароль" << std::endl;
	if (mm == '2') std::cout << "Некорректный ввод" << std::endl;

	std::cout << "Введите логин:" << std::endl;

	std::cin >> *login;
	std::cin.sync();

	std::cout << "Введите пароль:" << std::endl;

	std::cin >> *pass;
	std::cin.sync();


	return 0;
}

unsigned short ChatDisplay::AskRegister(char mm, std::string* login, std::string* pass, std::string* fullname)
{
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc='n';

	std::cout << "Консольный чат - Регистрация" << std::endl;

	while (!menudone)
	{


		if (mm == '1') std::cout << "Такой пользователь уже существует" << std::endl;
		if (mm == '2') std::cout << "Некорректный ввод" << std::endl;


		std::cout << "Введите имя:" << std::endl;

		std::cin >> *fullname;
		std::cin.sync();

		std::cout << "Введите логин:" << std::endl;

		std::cin >> *login;
		std::cin.sync();

		std::cout << "Введите пароль:" << std::endl;

		std::cin >> *pass;
		std::cin.sync();

		std::cout << "Введенные данные:" << std::endl;
		std::cout << "Имя:" << *fullname << std::endl;
		std::cout << "Логин:" << *login << std::endl;
		std::cout << "Пароль:" << *pass << std::endl;

		std::cout << "Подтверждаете? : (Y/n)" << std::endl;
		std::cin >> uc;
		std::cin.sync();

		if (uc == 'Y') menudone = 1;
	}

	return 0;
}

bool ChatDisplay::RetryMenu()
{
	std::cout << "Консольный чат - Повторить или отменить?" << std::endl;
	bool menudone = false;
	bool userchoice = 0;
	char uc;

	while (!menudone)
	{
		std::cout << "Ошибка. Выберите действие:" << std::endl;
		std::cout << "1. Повторить" << std::endl;
		std::cout << "2. Отменить" << std::endl;
		std::cout << "Ввеедите номер:" << std::endl;
		std::cin >> uc;
		std::cin.sync();

		if (uc == '1')
		{
			userchoice = 1;
			menudone = 1;
		};

		if (uc == '2')
		{
			userchoice = 0;
			menudone = 1;
		}
	}


	return userchoice;
}

unsigned short ChatDisplay::SendRecieveLogoff()
{
	std::cout << "Консольный чат - Отправка/Получение" << std::endl;
	bool menudone = false;
	unsigned short  userchoice = 0;
	char uc;

	while (!menudone)
	{
		std::cout << "Выберите действие:" << std::endl;
		std::cout << "1. Отправить сообщение" << std::endl;
		std::cout << "2. Получить сообщения" << std::endl;
		std::cout << "3. Разлогиниться" << std::endl;
		std::cout << "Ввеедите номер:" << std::endl;
		std::cin >> uc;
		std::cin.sync();

		if (uc == '1')
		{
			userchoice = 1;
			menudone = 1;
		};

		if (uc == '2')
		{
			userchoice = 2;
			menudone = 1;
		}
		
		if (uc == '3')
		{
			userchoice = 3;
			menudone = 1;
		}

	}


	return userchoice;
}

unsigned short ChatDisplay::SendMenu(std::string* reciever, std::string* msgbody)
{
	
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc = 'n';
	std::string tmpreciever;
	std::string tmpmsgbody;

	std::cout << "Консольный чат - Отправка сообщения" << std::endl;

	while (!menudone)
	{

		std::cout << "Введите логин получателя. Используйте * для отправки всем:" << std::endl;

		std::cin >> tmpreciever;
		std::cin.sync();

		std::cout << "Введите сообщение:";// << std::endl;
		std::cin.ignore();
		std::getline(std::cin, tmpmsgbody);
		//std::cin.sync();

		
		std::cout << "Введенные данные:" << std::endl;
		std::cout << "Логин:" << tmpreciever << std::endl;
		std::cout << "Сообщение:" <<tmpmsgbody<<std::endl;
		


		std::cout << std::endl << "Подтверждаете? : (Y/n)" << std::endl;

		std::cin >> uc;
		std::cin.sync();

		if (uc == 'Y')
		{
			menudone = 1;
			userchoice = 1;
			(*reciever) = tmpreciever;
			(*msgbody) = tmpmsgbody;
		}
		else
		{
			menudone = 0;
			userchoice = 0;
		}
	}
	return userchoice;
}

