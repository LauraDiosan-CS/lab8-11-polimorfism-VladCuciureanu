#pragma once
#include "Repository.h"
#include "Utilizator.h"
#include <vector>
class ServiceUtilizator
{
protected:
	Repository<Utilizator>* repo; // Reference to repo
public:
	ServiceUtilizator(); // Blank constructor
	ServiceUtilizator(Repository<Utilizator>* repo); // Parameterized constructor
	~ServiceUtilizator(); // Destructor
	void addUtilizator(std::string name, std::string email, int level); // Tries to add an user to the repo
	std::vector<Utilizator> getUtilizatori(); // Returns all users
	Utilizator getUtilizatorById(int id); // Returns the user with given id
	void updateUtilizator(int id, std::string name, std::string email, int level); // Updates the user with given id with given values.
	void deleteUtilizator(int id); // Deletes the user with the given id.
};

