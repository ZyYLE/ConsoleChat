#pragma once

#include <string>

class ChatUser
{
	std::string _username;
	std::string _userpass;
	unsigned short _userid;
	unsigned short _usermode; // предназначена для указания привилегий пользователя в чате

public:
	
	ChatUser(std::string n, std::string p, unsigned short ui, unsigned short um);
	//ChatUser(const ChatUser& p);
	//ChatUser& operator= (const ChatUser& p);


	void SetUsername(std::string s);
	std::string GetUsername();

	void SetUserpass(std::string s);
	std::string GetUserpass();

	void SetUserID(unsigned short id);
	unsigned short GetUserID(); 


	void SetUsermode(unsigned short m);
	unsigned short GetUsermode();

	void InitChatUser();



};

