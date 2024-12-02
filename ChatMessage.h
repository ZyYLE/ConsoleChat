#pragma once

#include <string>

class ChatMessage
{
	protected:
		std::string _msgbody;							// ����� ���������
		std::string _msgtime;							//���� ����� ��������
		bool _readflag;									// ���� ���������
		unsigned short _msgsender;						// �����������
		unsigned short _msgreciever;					//����������, ���� 0 �� ����. 

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

