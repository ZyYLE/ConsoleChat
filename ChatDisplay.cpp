#include "ChatDisplay.h"

void ChatDisplay::ShowWelcome()
{
	std::cout << "���������� ��� - ������� �����" << std::endl;
}

unsigned short ChatDisplay::LoginMenu()
{
	std::cout << "���������� ��� - �����/�����������" << std::endl;
	bool menudone = false;
	unsigned short userchoice=0;
	char uc;
	
	while (!menudone)
	{
		std::cout << "�������� ��������:" << std::endl;
		std::cout << "1. ������ ����� � ������" << std::endl;
		std::cout << "2. ������������������" << std::endl;
		std::cout << "�������� �����:" << std::endl;
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

	std::cout << "���������� ��� - �����������" << std::endl;
	
	if (mm == '1') std::cout << "����� ������������ ��� ����" << std::endl;
	if (mm == '2') std::cout << "������������ ����" << std::endl;

	std::cout << "������� �����:" << std::endl;
		
	std::cin >> *login;
	std::cin.sync();

	std::cout << "������� ������:" << std::endl;

	std::cin >> *pass;
	std::cin.sync();

	return 0;
}

unsigned short ChatDisplay::AskLogin(char mm, std::string* login, std::string* pass)
{
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc;

	std::cout << "���������� ��� - ����" << std::endl;

	if (mm == '1') std::cout << "�������� ����� ��� ������" << std::endl;
	if (mm == '2') std::cout << "������������ ����" << std::endl;

	std::cout << "������� �����:" << std::endl;

	std::cin >> *login;
	std::cin.sync();

	std::cout << "������� ������:" << std::endl;

	std::cin >> *pass;
	std::cin.sync();


	return 0;
}

unsigned short ChatDisplay::AskRegister(char mm, std::string* login, std::string* pass, std::string* fullname)
{
	bool menudone = false;
	unsigned short userchoice = 0;
	char uc='n';

	std::cout << "���������� ��� - �����������" << std::endl;

	while (!menudone)
	{


		if (mm == '1') std::cout << "����� ������������ ��� ����������" << std::endl;
		if (mm == '2') std::cout << "������������ ����" << std::endl;


		std::cout << "������� ���:" << std::endl;

		std::cin >> *fullname;
		std::cin.sync();

		std::cout << "������� �����:" << std::endl;

		std::cin >> *login;
		std::cin.sync();

		std::cout << "������� ������:" << std::endl;

		std::cin >> *pass;
		std::cin.sync();

		std::cout << "��������� ������:" << std::endl;
		std::cout << "���:" << *fullname << std::endl;
		std::cout << "�����:" << *login << std::endl;
		std::cout << "������:" << *pass << std::endl;

		std::cout << "�������������? : (Y/n)" << std::endl;
		std::cin >> uc;
		std::cin.sync();

		if (uc == 'Y') menudone = 1;
	}

	return 0;
}

bool ChatDisplay::RetryMenu()
{
	std::cout << "���������� ��� - ��������� ��� ��������?" << std::endl;
	bool menudone = false;
	bool userchoice = 0;
	char uc;

	while (!menudone)
	{
		std::cout << "������. �������� ��������:" << std::endl;
		std::cout << "1. ���������" << std::endl;
		std::cout << "2. ��������" << std::endl;
		std::cout << "�������� �����:" << std::endl;
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
	std::cout << "���������� ��� - ��������/���������" << std::endl;
	bool menudone = false;
	unsigned short  userchoice = 0;
	char uc;

	while (!menudone)
	{
		std::cout << "�������� ��������:" << std::endl;
		std::cout << "1. ��������� ���������" << std::endl;
		std::cout << "2. �������� ���������" << std::endl;
		std::cout << "3. �������������" << std::endl;
		std::cout << "�������� �����:" << std::endl;
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

	std::cout << "���������� ��� - �������� ���������" << std::endl;

	while (!menudone)
	{

		std::cout << "������� ����� ����������. ����������� * ��� �������� ����:" << std::endl;

		std::cin >> tmpreciever;
		std::cin.sync();

		std::cout << "������� ���������:";// << std::endl;
		std::cin.ignore();
		std::getline(std::cin, tmpmsgbody);
		//std::cin.sync();

		
		std::cout << "��������� ������:" << std::endl;
		std::cout << "�����:" << tmpreciever << std::endl;
		std::cout << "���������:" <<tmpmsgbody<<std::endl;
		


		std::cout << std::endl << "�������������? : (Y/n)" << std::endl;

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

