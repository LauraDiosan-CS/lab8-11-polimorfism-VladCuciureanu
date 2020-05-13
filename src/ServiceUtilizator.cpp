#include "ServiceUtilizator.h"

ServiceUtilizator::ServiceUtilizator()
{
	this->repo = new Repository<Utilizator>();
}

ServiceUtilizator::ServiceUtilizator(Repository<Utilizator>* repo)
{
	this->repo = repo;
}

ServiceUtilizator::~ServiceUtilizator()
{
	delete this->repo;
}

void ServiceUtilizator::addUtilizator(std::string name, std::string email, int level)
{
	Utilizator* u = new Utilizator(repo->getSize(), name, email, level);
	//TODO: VALIDARE
	this->repo->add(u);
}

std::vector<Utilizator> ServiceUtilizator::getUtilizatori()
{
	std::vector<Utilizator> result;

	for (Utilizator* m : this->repo->getAll())
	{
		result.push_back(*(m->clone()));
	}
	return result;
}

Utilizator ServiceUtilizator::getUtilizatorById(int id)
{
	return *(this->repo->getById(id)->clone());
}

void ServiceUtilizator::updateUtilizator(int id, std::string newName, std::string newEmail, int newLevel)
{
	Utilizator* u = new Utilizator(id, newName, newEmail, newLevel);
	//TODO : VALIDARE
	this->repo->update(this->repo->getById(id), u);
}

void ServiceUtilizator::deleteUtilizator(int id)
{
	this->repo->remove(this->repo->getById(id));
}
