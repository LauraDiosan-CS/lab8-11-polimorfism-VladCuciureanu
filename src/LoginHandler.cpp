#include "LoginHandler.h"

LoginHandler::LoginHandler()
{
	this->su = nullptr;
	this->should_exit = false;
	this->user_id = -1;
}

LoginHandler::LoginHandler(ServiceUtilizator* su)
{
	this->su = su;
	this->should_exit = false;
	this->user_id = -1;
}

LoginHandler::~LoginHandler()
{
}

bool LoginHandler::login(std::string email)
{
	std::vector<Utilizator*> users = this->su->getAll();
	for (Utilizator* u : users)
	{
		if (u->getEmail() == email)
		{
			this->user_id = u->getId();
			return true;
		}
	}
	throw "Invalid email! Try again";
}
