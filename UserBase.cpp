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

bool UserBase::AddUser(ChatUser chatuser)
{
	
	
	if (_totalusers < _userbasesize)
	{
		_startuserPtr[_totalusers] = chatuser;
		
		_totalusers++;
				
	}
	else
	{
		_totalusers++;
		_userbasesize++;
		
		void* tmpptr;

		tmpptr = realloc((void *)_startuserPtr, (_userbasesize * sizeof(ChatUser)));

		if (tmpptr == nullptr)
		{
			return false;
		}
		else
		{
			_startuserPtr = (ChatUser*)tmpptr;
			memset(_startuserPtr + _userbasesize - 1, 0, sizeof(ChatUser));

			_startuserPtr[_totalusers - 1].InitChatUser();
			
			_startuserPtr[_totalusers - 1] = chatuser;
		}
				
		return true;
	}

	
}

bool UserBase::CheckNick(std::string nickname)
{
	bool nf = false;
	int i = 0;
	while ((!nf)&&(i<_totalusers))
	{
		std::string tmpst = _startuserPtr[i].GetUsername();
		if (tmpst == nickname)
		{
			nf = true;
		}
		i++;
	}

	return nf;
}

void UserBase::ListUsers()
{
	for (int i = 0; i < _totalusers; i++)
	{
		std::string tmpun;
		tmpun = _startuserPtr[i].GetUsername();
		std::cout << tmpun << std::endl;

	}

	


}




