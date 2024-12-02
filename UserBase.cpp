#include "UserBase.h"
#include <iostream>

UserBase::UserBase(unsigned short userbasesize)
{
	_startuserPtr = (ChatUser*)calloc(userbasesize, sizeof(ChatUser));
	_totalusers = 0;
	_userbasesize = userbasesize;

	for (int i = 0; i < _userbasesize; i++)
	{
		_startuserPtr[i].InitChatUser();


	};


}

UserBase::~UserBase()
{
	free(_startuserPtr);
}

bool UserBase::AddUser(ChatUser* chatuser)
{


	if (_totalusers < _userbasesize)
	{
		_startuserPtr[_totalusers] = (*chatuser);

		_totalusers++;

	}
	else
	{
		_totalusers++;
		_userbasesize++;

		void* tmpptr;

		
			tmpptr = realloc((void*)_startuserPtr, (_userbasesize * sizeof(ChatUser)));
		;

		if (tmpptr == nullptr)
		{
			return false;
		}
		else
		{
			_startuserPtr = (ChatUser*)tmpptr;
			memset(_startuserPtr + _userbasesize - 1, 0, sizeof(ChatUser));

			_startuserPtr[_totalusers - 1].InitChatUser();

			_startuserPtr[_totalusers - 1] = (*chatuser);
		}


	}
	// На этот момент  элемент списка юзеров заполнен всеми полями переданного юзера
	// Теперь заполняем автоматическое поле ID

	if (_totalusers == 1)
	{
		_startuserPtr[_totalusers - 1].SetUserID(1);
	}
	else
	{
		_startuserPtr[_totalusers - 1].SetUserID(_startuserPtr[_totalusers - 2].GetUserID()+1);

	};

	(*chatuser) = _startuserPtr[_totalusers - 1]; //передаем с заполненным ID  обратно

	

	return true;

}

bool UserBase::CheckNick(ChatUser* chatuser)
{
	bool nf = false; // nick found
	int i = 0;
	while ((!nf) && (i < _totalusers))
	{
		std::string tmpst = _startuserPtr[i].GetUsername();
		if (tmpst == chatuser->GetUsername())
		{
			nf = true;
			(*chatuser) = _startuserPtr[i];
		}
		i++;
	}

	return nf;
}

void UserBase::ListUsers()
{
	
	std::cout << "Список зарегистророванных пользователей. Всего: " << _totalusers << std::endl;

	for (int i = 0; i < _totalusers; i++)
	{
		
		std::cout <<"Полное имя: "<<  _startuserPtr[i].GetUserfullname() << std::endl << "Логин: " << _startuserPtr[i].GetUsername() << std::endl << "UserID: "<<_startuserPtr[i].GetUserID() << std::endl << std::endl;

	}




}

bool UserBase::CheckLogin(ChatUser* chatuser)
{
	bool userfound = false;
	unsigned short ix = 0;
	while ((!userfound) && (ix < _totalusers))
	{
		if ((_startuserPtr[ix].GetUsername() == (*chatuser).GetUsername()) && (_startuserPtr[ix].GetUserpass() == (*chatuser).GetUserpass()))
		{
			userfound = true;
			(*chatuser) = _startuserPtr[ix];

		}
		ix++;
	}
	return userfound;
}




