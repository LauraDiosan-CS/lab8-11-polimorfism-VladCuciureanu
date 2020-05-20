#include <iostream>
#include <assert.h>
#include "Tests.h"
#include "UserInterface.h"

int main()
{
	Tests::run_tests();
	
	bool should_exit = false;
	
	RepositoryFileCSV<Utilizator>* userRepository = new RepositoryFileCSV<Utilizator>("users.dat");
	RepositoryFileCSV<Medicament>* medicineRepository = new RepositoryFileCSV<Medicament>("meds.dat");
	ServiceUtilizator* userService = new ServiceUtilizator(userRepository);
	MedicineService* medsService = new MedicineService(medicineRepository);
	LoginHandler* loginHandler = new LoginHandler(userService);
	UserInterface* userInterface = new UserInterface(userService, medsService, loginHandler);

	//userService->add("Vlad", "t", 9);
	while (!should_exit)
	{
		userInterface->login_loop();
		should_exit = loginHandler->should_exit;
		if (!should_exit)
		{
			std::cout << "--------------------------------------------------------\n";
			std::cout << "\nMedicamente:\n\n";
			for (Medicament* m : medsService->getAll())
			{
				std::cout << m->toString(", ") << '\n';
			}
			std::cout << "--------------------------------------------------------\n";
			std::cout << "\nUtilizatori:\n\n";
			for (Utilizator* u : userService->getAll())
			{
				std::cout << u->toString(", ") << '\n';
			}
			std::cout << "\n--------------------------------------------------------\n";
			std::cout << "\n";
			userInterface->loop(loginHandler->user_id);
		}
	}
	return 0;
}