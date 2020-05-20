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
	MedicineService* sm;
	ServiceUtilizator* su;
	LoginHandler* lh;
public:
	UserInterface(); // Blank constructor
	UserInterface(ServiceUtilizator* su, MedicineService* sm, LoginHandler* lh); // Parameterized constructor
	~UserInterface(); // Destructor
	void login_loop(); // Login loop
	void loop(int loggedUserId); // Main UI loop
};

