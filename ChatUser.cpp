#include "ChatUser.h"

ChatUser::ChatUser(std::string n, std::string p, unsigned short ui, unsigned short um)
{
	_username = n;
	_userpass = p;
	_userid = ui;
	_usermode = um;
}

/*
ChatUser::ChatUser(const ChatUser& p)
{
	_username = p._username;
	_userpass = p._userpass;
	_userid = p._userid;
	_usermode = p._usermode;
}

ChatUser& ChatUser::operator=(const ChatUser& p)
{
	_username = p._username;
	_userpass = p._userpass;
	_userid = p._userid;
	_usermode = p._usermode;
	return *this;
}
*/

void ChatUser::SetUsername(std::string s)
{
	_username = s;
}

std::string ChatUser::GetUsername()
{
	return _username;
}

void ChatUser::SetUserpass(std::string s)
{
	_userpass = s;
}

std::string ChatUser::GetUserpass()
{
	return _userpass;
}

void ChatUser::SetUserID(unsigned short id)
{
	_userid = id;
}

unsigned short ChatUser::GetUserID()
{
	return _userid;
}

void ChatUser::SetUsermode(unsigned short m)
{
	_usermode = m;
}

unsigned short ChatUser::GetUsermode()
{
	return _usermode;
}

void ChatUser::InitChatUser()
{
	_username = " ";
	_userpass = " ";
}



