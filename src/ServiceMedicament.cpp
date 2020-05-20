#include "ServiceMedicament.h"

MedicineService::MedicineService()
{
	this->repo = new Repository<Medicament>();
}

MedicineService::MedicineService(Repository<Medicament>* repo)
{
	this->repo = repo;
}

MedicineService::~MedicineService()
{
	delete this->repo;
}

void MedicineService::add(std::string name, bool prescription, int stock, std::string brand)
{
	Medicament* m = new Medicament(this->repo->getSize(), name, prescription, stock, brand);
	MedicineValidator::validate(m);
	this->repo->add(m);
}

void MedicineService::add(Medicament* m)
{
	this->repo->add(m->clone());
}

std::vector<Medicament*> MedicineService::getAll()
{
	std::vector<Medicament*> result;

	for (Medicament* m : this->repo->getAll())
	{
		result.push_back(m->clone());
	}
	return result;
}

Medicament MedicineService::getMedicineById(int id)
{
	return *(this->repo->getById(id)->clone());
}

std::vector<Medicament*> MedicineService::search(std::string query)
{
	std::vector<Medicament*> result;

	for (Medicament* m : this->repo->getAll())
	{
		if (m->getName().find(query) != std::string::npos)
		{
			result.push_back(m->clone());
		}
	}
	return result;
}

void MedicineService::update(int id, std::string newName, bool newPrescription, int newStock, std::string newBrand)
{
	Medicament* m = new Medicament(id, newName, newPrescription, newStock, newBrand);
	MedicineValidator::validate(m);
	this->repo->update(this->repo->getById(id), m);
}

void MedicineService::update(Medicament* mOld, Medicament* mNew)
{
	this->repo->update(mOld, mNew);
}

void MedicineService::remove(int id)
{
	this->repo->remove(this->repo->getById(id));
}
