#pragma once

#include <string>

class ChatMessage
{
	protected:
		std::string _msgbody;							// текст сообщения
		std::string _msgtime;							//дата время отправки
		bool _readflag;									// флаг прочтения
		unsigned short _msgsender;						// отправитель
		unsigned short _msgreciever;					//получатель, если 0 то всем. 

	public:
		ChatMessage(std::string msgbody, std::string msgtime, bool readflag, unsigned short msgsender, unsigned short msgreciever);
	//	ChatMessage();

		bool GetReadFlag();
		void SetReadFlag(bool readflag);

		unsigned short GetSender();
		unsigned short GetReciever();
		std::string GetMsgBody();
		void SetMsgBody(std::string msgbody);
		
		std::string GetMsgTime();
		void SetMsgTime(std::string msgtime);

		void InitMsg();

		void PrintMsg();

};

