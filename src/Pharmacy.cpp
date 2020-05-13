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
	ServiceMedicament* medsService = new ServiceMedicament(medicineRepository);
	LoginHandler* loginHandler = new LoginHandler(userService);
	UserInterface* userInterface = new UserInterface(userService, medsService, loginHandler);

	while (!should_exit)
	{
		userInterface->login_loop();
		should_exit = loginHandler->should_exit;
		if (!should_exit)
		{
			//UI loop
		}
	}
	return 0;
}