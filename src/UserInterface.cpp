#include "UserInterface.h"

UserInterface::UserInterface()
{
	this->sm = nullptr;
	this->lh = nullptr;
	this->su = nullptr;
}

UserInterface::UserInterface(ServiceUtilizator* su, MedicineService* sm, LoginHandler* lh)
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
		std::string pass;
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
				std::cout << "\nPassword: ";
				std::cin >> pass;
				try {
					if (this->lh->login(email, pass))
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

void UserInterface::loop(int loggedUserId)
{
	bool trigger = false;
	std::cout << "Welcome " << su->getUtilizatorById(loggedUserId).getName() << "!\n\n";
	while (!trigger) {
		int choice;
		std::string query;
		Utilizator ut = Utilizator();
		// Show menu
		std::cout << "1. Query meds\n2. Medicine Menu\n3. Modify user clearance level\n4. View all users\n\n0. Exit\n";
		std::cout << "Choice: ";
		try {
			std::cin >> choice;
			std::cout << "\n";
			switch (choice) {
			case 1:
				//Query meds
				std::cout << "Query: ";
				std::cin >> query;
				if (sm->search(query).size() == 0)
				{
					std::cout << "\nCouldn't find any medicine with given query.\n\n\n";
				}
				else
				{
					for (Medicament* m : sm->search(query))
					{
						std::cout << m->toString(", ") << '\n';
					}
					std::cout << '\n';
				}
				break;
			case 2:
				std::cout << "1. Add med\n2. Show meds\n3. Update med\n4. Delete med\n\n0. Exit\n";
				std::cout << "Choice: ";
				std::cin >> choice;
				std::cout << "\n";
				switch (choice)
				{
				case 1:
					//name, prescription, stock, brand
				{
					try {
						std::string name;
						char prescription;
						int stock;
						std::string brand;
						std::cout << "Name: ";
						std::cin >> name;
						std::cout << "Prescription: (y/n)";
						std::cin >> prescription;
						if (prescription != 'y' && prescription != 'n')
						{
							std::cout << "Invalid choice! Valid choices: y/n (case-sensitive)";
							break;
						}
						std::cout << "Stock: ";
						std::cin >> stock;
						std::cout << "Brand: ";
						std::cin >> brand;
						sm->add(name, prescription == 'y', stock, brand);
						std::cout << "\n\n";
					}
					catch (std::string error) {
						std::cout << error;
					}
				}
					break;
				case 2:
					std::cout << "\nMedicamente:\n\n";
					for (Medicament* m : sm->getAll())
					{
						std::cout << m->toString(", ") << '\n';
					}
					std::cout << "\n\n";
					break;
				case 3:
					try {
						std::cout << "Medicine ID to update: ";
						int medicineId;
						std::cin >> medicineId;
						std::cout << '\n';
						Medicament m = sm->getMedicineById(medicineId);
						std::cout << m.toString(", ");
						std::cout << "\n\n";
						std::string name;
						char prescription;
						int stock;
						std::string brand;
						std::cout << "Name: ";
						std::cin >> name;
						std::cout << "Prescription: (y/n/enter)";
						std::cin >> prescription;
						if (prescription != 'y' && prescription != 'n' && prescription!='\n')
						{
							std::cout << "Invalid choice! Valid choices: y/n (case-sensitive)";
							break;
						}
						if (prescription == '\n')
							prescription = m.getPrescription()?'y':'f';
						std::cout << "Stock: ";
						std::cin >> stock;
						std::cout << "Brand: ";
						std::cin >> brand;
						if (brand == "")
							brand = m.getBrand();
						sm->update(medicineId ,name, prescription == 'y', stock, brand);
					}
					catch (std::string error) {
						std::cout << error;
					}
					std::cout << "\n";
					break;
				case 4:
				{
					std::cout << "Medicine ID to remove: ";
					int medicineId;
					std::cin >> medicineId;
					try {
						sm->remove(medicineId);
					}
					catch (std::string error) {
						std::cout << error;
					}
				}
				std::cout << "\n\n";
					break;
				case 0:
					break;
				}
				break;
			case 3:
				//Modify user clearance level
				
				std::cout << "Choice: ";
				std::cin >> choice;
				
				try {
					ut = su->getUtilizatorById(choice);
				}
				catch (std::string error)
				{
					std::cout << error << '\n';
				}
				std::cout << "New user clearance level: ";
				std::cin >> choice;
				if (su->getUtilizatorById(loggedUserId).getLevel() > choice)
					su->update(ut.getId(), ut.getName(), ut.getEmail(), ut.getPass(), choice);
				else
					std::cout << "New level must be strictly lower than your level.\n\n\n";
				break;
			case 4:
				//View all users
				for (Utilizator* u : su->getAll())
				{
					std::cout << u->toString(", ") << "\n\n";
				}
				std::cout << '\n';
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
