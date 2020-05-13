#include "UserInterface.h"

UserInterface::UserInterface()
{
	this->sm = nullptr;
	this->lh = nullptr;
	this->su = nullptr;
}

UserInterface::UserInterface(ServiceUtilizator* su, ServiceMedicament* sm, LoginHandler* lh)
{
	this->su = su;
	this->sm = sm;
	this->lh = lh;
}

UserInterface::~UserInterface()
{
}

void UserInterface::login_loop()
{
	bool trigger = false;
	std::cout << "Welcome!\n\n";
	while (!trigger) {
		int choice;
		std::string email;
		// Show menu
		std::cout << "1. Login\n\n0. Exit\n";
		std::cout << "Choice: ";
		try {
			std::cin >> choice;
			std::cout << "\n";
			switch (choice) {
			case 1:
				//Login
				std::cout << "Email: ";
				std::cin >> email;
				try {
					if (this->lh->login(email))
					{
						trigger = true;
						std::cout << "\nSuccessfully logged in!\n\n";
					}
				}
				catch (std::string exception)
				{
					std::cout << exception << "\n\n";
				}
				break;
			case 0:
				//Exit
				this->lh->should_exit = true;
				trigger = true;
				break;
			default:
				std::cout << "Invalid option! Try again!\n\n";
				break;
			}
		}
		catch (const char* exception)
		{
			std::cout << "\nPlease input a valid option...\n\n";
		}
	}
}

void UserInterface::loop()
{
}
