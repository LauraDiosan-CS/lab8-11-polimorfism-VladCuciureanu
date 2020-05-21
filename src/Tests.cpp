#include "Tests.h"
#include <assert.h>
#include <stdexcept>
#include <random>

std::string random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

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
		Utilizator* f = new Utilizator(1, "vlad", "t","f", 9);
		ur->add(f);
		ServiceUtilizator* su = new ServiceUtilizator(ur);
		LoginHandler* lh = new LoginHandler(su);
		try {
			assert(lh->login("t", "f") == true); // login
		}
		catch (std::exception ex)
		{
			std::cout << ex.what();
		}
		lh->logout(); // logout
		try {
			assert(lh->login("t", "f") == true); // login
		}
		catch (std::exception ex)
		{
			std::cout << ex.what();
		}
		assert(lh->should_exit == false);
		bool trigger = false;
		// invalid email
		try {
			lh->login("f","t");
		}
		catch (std::exception ex)
		{
			assert(strcmp(ex.what(), "Invalid email! Try again") == 0);
		}
		// invalid pass
		try {
			lh->login("t", "t");
		}
		catch (std::exception ex)
		{
			assert(strcmp(ex.what(), "Invalid password! Try again") == 0);
		}
	}
	{
		int e_count = rand() % 100 + 101; // random 100 + 200
		Repository<Utilizator>* ur = new Repository<Utilizator>();
		ServiceUtilizator* su = new ServiceUtilizator(ur);
		LoginHandler* lh = new LoginHandler(su);
		// generare
		for (int i = 0; i < e_count; i++)
		{
			std::string lname = random_string(10);
			std::string sname = random_string(10);
			std::string name = sname + " " + lname;
			std::string email = sname + "@" + lname + ".com";
			std::string pass = random_string(10);
			int level = rand() % 10;
			su->add(name, email, pass, level);
		}
		// executare
		int a_index, b_index;
		a_index = rand() % su->getAll().size();
		b_index = a_index;
		while (b_index == a_index)
			b_index = rand() % su->getAll().size();
		int count = 0;
		while (count < 1000)
		{
			Utilizator u = su->getUtilizatorById(a_index);
			Utilizator u2 = su->getUtilizatorById(b_index);
			lh->login(u.getEmail(), u.getPass());
			if (u.getLevel() > u2.getLevel())
			{
				su->update_clearance(u.getId(), u2.getId(), rand() % u.getLevel());
				count++;
			}
			else
			{
				try {
					su->update_clearance(u.getId(), u2.getId(), rand() % u.getLevel());
				}
				catch (std::exception ex)
				{
					count++;
				}
			}
		}
	}
	std::cout << "Passed all tests successfully.\n";
}