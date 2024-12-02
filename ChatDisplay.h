#pragma once
#include <string>
#include <iostream>

class ChatDisplay
{
	protected:
		//unsigned short _loggeduserid;
		//std::string _loggedusernick;

	public:
		void ShowWelcome();
		unsigned short LoginMenu();
		unsigned short RegisterMenu(char mm, std::string* login, std::string* pass);
		unsigned short  AskLogin(char mm, std::string* login, std::string* pass);
		unsigned short  AskRegister(char mm, std::string* login, std::string* pass, std::string* fullname);
		bool RetryMenu();
		unsigned short SendRecieveLogoff();
		unsigned short SendMenu(std::string* reciever, std::string* msgbody);

		//unsigned short RecieveMenu();
};

