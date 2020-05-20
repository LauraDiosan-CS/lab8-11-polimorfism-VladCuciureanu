#pragma once
#include "ServiceUtilizator.h"
class LoginHandler
{
protected:
	ServiceUtilizator* su; // Self-explainatory
public:
	bool should_exit; // Exit trigger
	int user_id; // Logged in user id
	LoginHandler(); // Blank constructor
	LoginHandler(ServiceUtilizator* su); // Parameterized constructor
	~LoginHandler(); // Destructor
	bool login(std::string email); // Login method
};

