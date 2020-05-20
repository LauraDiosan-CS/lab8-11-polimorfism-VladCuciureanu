#include "Tests.h"
#include <assert.h>

void Tests::run_tests()
{
	{
		Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
		Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

		repo->add(m1);
		repo->add(m2);
		assert(repo->getAll().size() == 2);
		assert(*repo->getAll()[0] == *m1);
		assert(*repo->getAll()[1] == *m2);
		repo->add(m3);
		assert(*repo->getAll()[2] == *m3);

		Medicament m1_new(100, "paracetamol", false, 50, "p1");
		repo->update(m1, &m1_new);
		assert(*repo->getAll()[0] != *m1);
		assert(*repo->getAll()[0] == m1_new);

		repo->remove(200);
		assert(repo->getAll().size() == 2);
	}
	{
		Repository<Medicament>* repository = new Repository<Medicament>();
		MedicineService* service = new MedicineService{ repository };
		Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

		service->add(m1);
		service->add(m2);
		assert(service->getAll().size() == 2);
		assert(*service->getAll()[0] == *m1);
		assert(*service->getAll()[1] == *m2);
		service->add(m3);
		assert(*service->getAll()[2] == *m3);

		assert(service->search("ic").size() == 1);
		assert(service->search("a").size() == 3);

		Medicament m1_new(100, "altceva", false, 50, "p1");
		service->update(m1, &m1_new);
		assert(service->search("al").size() == 2);
		assert(*service->search("al")[0] == m1_new);
		assert(*service->search("al")[1] == *m2);
		service->remove(200);
		assert(service->search("al").size() == 1);
		assert(*service->search("al")[0] == m1_new);
	}
	{
		Repository<Utilizator>* ur = new Repository<Utilizator>();
		Utilizator* f = new Utilizator(1, "vlad", "t", 9);
		ur->add(f);
		ServiceUtilizator* su = new ServiceUtilizator(ur);
		LoginHandler* lh = new LoginHandler(su);
		assert(lh->login("t") == true);
		assert(lh->should_exit == false);
		bool trigger = false;
		try {
			lh->login("f");
		}
		catch (const char* exception)
		{
			trigger = true;
		}
		assert(trigger);
	}
	std::cout << "Passed all tests successfully.\n";
}