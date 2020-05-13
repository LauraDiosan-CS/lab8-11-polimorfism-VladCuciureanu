#include "Tests.h"

void Tests::run_tests()
{
	{
		// Domain
		Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
		Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

		// Repo
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
	// Service
	{
		Repository<Medicament>* repo = new Repository<Medicament>();
		Medicament* m1 = new Medicament(0, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(1, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(2, "antibiotic", true, 70, "p3");
		ServiceMedicament* s = new ServiceMedicament(repo);
		s->addMedicament("parasinus", false, 10, "p1");
		s->addMedicament("ketonal", false, 90, "p2");
		s->addMedicament("antibiotic", true, 70, "p3");
		std::vector<Medicament> v = s->getMeds();
		assert(v.size() == 3);
		assert(v.at(0) == *m1);
		assert(v.at(1) == *m2);
		assert(v.at(2) == *m3);
		s->updateMedicine(0, "t", true, 11, "p4");
		s->deleteMedicine(2);
		v = s->getMeds();
		assert(v.size() == 2);
		assert(v.at(0).getName() == "t");
		assert(v.at(0).getPrescription() == true);
		assert(v.at(0).getStock() == 11);
		assert(v.at(0).getBrand() == "p4");
		assert(s->getMedicineById(1) == *m2);
	}
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