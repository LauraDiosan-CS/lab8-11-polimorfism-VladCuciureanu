#pragma once
#include "Repository.h"
#include "Medicament.h"
#include "ServiceUtilizator.h"
#include "MedicineValidator.h"
#include <vector>
class MedicineService
{
protected:
	Repository<Medicament>* repo; // Reference to repo
public:
	MedicineService(); // Blank constructor
	MedicineService(Repository<Medicament>* repo); // Parameterized constructor
	~MedicineService(); // Destructor
	void add(std::string name, bool prescription, int stock, std::string brand); // Tries to add a medicine to repo
	void add(Medicament* m); // Tries to add a medicine to repo
	std::vector<Medicament*> getAll(); // Returns all medicine
	Medicament getMedicineById(int id); // Returns the medicine with given id
	std::vector<Medicament*> search(std::string query); // Returns the medicine with given id
	void update(int id, std::string newName, bool newPrescription, int newStock, std::string newBrand); // Updates medicine with given id with given values
	void update(Medicament* mOld, Medicament* mNew); // Updates medicine with given id with given values
	void remove(int id); // Deletes medicine with given id
};

