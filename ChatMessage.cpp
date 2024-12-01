#include "ChatMessage.h"
#include <iostream>

ChatMessage::ChatMessage(std::string msgbody, std::string msgtime, bool readflag, unsigned short msgsender, unsigned short msgreciever)
{
	_msgbody = msgbody;
	_msgtime = msgtime;
	_readflag = readflag;
	_msgsender = msgsender;
	_msgreciever = msgreciever;

}
/*
ChatMessage::ChatMessage()
{
	_msgbody = 1;
	_msgtime = 1;
	_readflag = 0;
	_msgsender = 0;
	_msgreciever = 0;
}*/



bool ChatMessage::GetReadFlag()
{
	return _readflag;
}

void ChatMessage::SetReadFlag(bool readflag)
{
	_readflag = readflag;
}

unsigned short ChatMessage::GetSender()
{
	return _msgsender;
}

unsigned short ChatMessage::GetReciever()
{
	return _msgreciever;
}

std::string ChatMessage::GetMsgBody()
{
	return _msgbody;
}

void ChatMessage::SetMsgBody(std::string msgbody)
{
	_msgbody = msgbody;
}

std::string ChatMessage::GetMsgTime()
{
	return _msgtime;
}

void ChatMessage::SetMsgTime(std::string msgtime)
{
	_msgtime = msgtime;
}

void ChatMessage::InitMsg()
{
	_msgbody = " ";
	_msgtime = " ";
}

void ChatMessage::PrintMsg()
{
	std::cout << "Отправитель: " << _msgsender << " Получатель: " << _msgreciever << " Время отправки: " << _msgtime << std::endl;
	std::cout << _msgbody << std::endl;


}



