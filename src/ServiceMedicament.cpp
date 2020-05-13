#include "ServiceMedicament.h"

ServiceMedicament::ServiceMedicament()
{
	this->repo = new Repository<Medicament>();
}

ServiceMedicament::ServiceMedicament(Repository<Medicament>* repo)
{
	this->repo = repo;
}

ServiceMedicament::~ServiceMedicament()
{
	delete this->repo;
}

void ServiceMedicament::addMedicament(std::string name, bool prescription, int stock, std::string brand)
{
	Medicament* m = new Medicament(this->repo->getSize(), name, prescription, stock, brand);
	// TODO: VALIDARE
	this->repo->add(m);
}

std::vector<Medicament> ServiceMedicament::getMeds()
{
	std::vector<Medicament> result;

	for (Medicament* m : this->repo->getAll())
	{
		result.push_back(*(m->clone()));
	}
	return result;
}

Medicament ServiceMedicament::getMedicineById(int id)
{
	return *(this->repo->getById(id)->clone());
}

void ServiceMedicament::updateMedicine(int id, std::string newName, bool newPrescription, int newStock, std::string newBrand)
{
	Medicament* m = new Medicament(id, newName, newPrescription, newStock, newBrand);
	// TODO : VALIDARE
	this->repo->update(this->repo->getById(id), m);
}

void ServiceMedicament::deleteMedicine(int id)
{
	this->repo->remove(this->repo->getById(id));
}
