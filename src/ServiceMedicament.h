#pragma once
#include "Repository.h"
#include "Medicament.h"
#include "ServiceUtilizator.h"
#include <vector>
class ServiceMedicament
{
protected:
	Repository<Medicament>* repo; // Reference to repo
public:
	ServiceMedicament(); // Blank constructor
	ServiceMedicament(Repository<Medicament>* repo); // Parameterized constructor
	~ServiceMedicament(); // Destructor
	void addMedicament(std::string name, bool prescription, int stock, std::string brand); // Tries to add a medicine to repo
	std::vector<Medicament> getMeds(); // Returns all medicine
	Medicament getMedicineById(int id); // Returns the medicine with given id
	void updateMedicine(int id, std::string newName, bool newPrescription, int newStock, std::string newBrand); // Updates medicine with given id with given values
	void deleteMedicine(int id); // Deletes medicine with given id
};

