#pragma once
#include <iostream>
#include "Tests.h"
#include "ServiceMedicament.h"
#include "ServiceUtilizator.h"
#include "LoginHandler.h"

class UserInterface
{
protected:
	// References to various services
	ServiceMedicament* sm;
	ServiceUtilizator* su;
	LoginHandler* lh;
public:
	UserInterface(); // Blank constructor
	UserInterface(ServiceUtilizator* su, ServiceMedicament* sm, LoginHandler* lh); // Parameterized constructor
	~UserInterface(); // Destructor
	void login_loop(); // Login loop
	void loop(); // Main UI loop
};

