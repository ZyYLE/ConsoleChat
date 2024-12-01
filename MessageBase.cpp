#include "MessageBase.h"



MessageBase::MessageBase(unsigned short msgbasesize)
{
	_msgbasesize=msgbasesize;
	_totalmsgs = 0;
	
	_startmsgPtr=(ChatMessage*)calloc(msgbasesize, sizeof(ChatMessage));

	for (int i = 0; i < _msgbasesize; i++)
	{
		_startmsgPtr[i].InitMsg();
		
	};
}

MessageBase::~MessageBase()
{
	free(_startmsgPtr);
}

bool MessageBase::AddMsg(ChatMessage chatmsg)
{
	if (_totalmsgs < _msgbasesize)
	{
		_startmsgPtr[_totalmsgs] = chatmsg;
		_totalmsgs++;
		
	}
	else
	{
		_totalmsgs++;
		_msgbasesize++;

		ChatMessage* tmpptr;

		tmpptr= (ChatMessage*)realloc(_startmsgPtr, _msgbasesize * sizeof(ChatMessage));

		if (tmpptr == nullptr)
		{
			return false;
		}
		else
		{
			_startmsgPtr = tmpptr;

			memset(_startmsgPtr + _msgbasesize - 1, 0, sizeof(ChatMessage));
			_startmsgPtr[_totalmsgs - 1].InitMsg();
			
			_startmsgPtr[_totalmsgs - 1] = chatmsg;
		}

	}

	return true;
}

ChatMessage MessageBase::GetMsg(unsigned short msgindex)
{
	return _startmsgPtr[msgindex];
}

void MessageBase::PrintAll()
{
	for (int ix = 0; ix < _totalmsgs; ix++)
	{
		_startmsgPtr[ix].PrintMsg();
	}
}

bool MessageBase::FindUserMsg(ChatUser* chatuser, MessageBase* dmb)
{
	bool found=0;

	for (int ix = 0; ix < _totalmsgs; ix++)
	{
		if ((_startmsgPtr[ix].GetReciever() == chatuser->GetUserID())||(_startmsgPtr[ix].GetReciever() == 0))
		{
			dmb->AddMsg(_startmsgPtr[ix]);
			found = 1;
		}
	}

	return found;
}



