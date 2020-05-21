#include "LoginHandler.h"
#include <stdexcept>

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

bool LoginHandler::login(std::string email, std::string pass)
{
	std::vector<Utilizator*> users = this->su->getAll();
	for (Utilizator* u : users)
	{
		if (u->getEmail() == email)
		{
			if (u->getPass() == pass) {
				this->user_id = u->getId();
				return true;
			}
			else{
				throw std::runtime_error("Invalid password! Try again");
				return false;
			}
		}
	}
	throw std::runtime_error("Invalid email! Try again");
	return false;
}

void LoginHandler::logout()
{
	this->user_id = -1;
	this->should_exit = false;
}
