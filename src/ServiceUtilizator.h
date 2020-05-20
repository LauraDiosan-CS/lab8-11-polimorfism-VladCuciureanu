#pragma once
#include "Repository.h"
#include "Utilizator.h"
#include "UtilizatorValidator.h"
#include <vector>
class ServiceUtilizator
{
protected:
	Repository<Utilizator>* repo; // Reference to repo
public:
	ServiceUtilizator(); // Blank constructor
	ServiceUtilizator(Repository<Utilizator>* repo); // Parameterized constructor
	~ServiceUtilizator(); // Destructor
	void add(Utilizator* u);
	void add(std::string name, std::string email, int level); // Tries to add an user to the repo
	std::vector<Utilizator*> getAll(); // Returns all users
	Utilizator getUtilizatorById(int id); // Returns the user with given id
	void update(Utilizator* uOld, Utilizator* uNew); // Updates the user with given id with given values.
	void update(int id, std::string name, std::string email, int level); // Updates the user with given id with given values.
	void remove(int id); // Deletes the user with the given id.
};

