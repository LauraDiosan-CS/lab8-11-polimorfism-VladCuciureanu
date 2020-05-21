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

void ServiceUtilizator::add(Utilizator* u)
{
	this->repo->add(u->clone());
}

void ServiceUtilizator::add(std::string name, std::string email, std::string pass, int level)
{
	Utilizator* u = new Utilizator(repo->getSize(), name, email, pass, level);
	UtilizatorValidator::validate(u);
	this->repo->add(u);
}

std::vector<Utilizator*> ServiceUtilizator::getAll()
{
	std::vector<Utilizator*> result;

	for (Utilizator* m : this->repo->getAll())
	{
		result.push_back(m->clone());
	}
	return result;
}

Utilizator ServiceUtilizator::getUtilizatorById(int id)
{
	return *(this->repo->getById(id)->clone());
}

void ServiceUtilizator::update(Utilizator* uOld, Utilizator* uNew)
{
	this->repo->update(uOld, uNew);
}

void ServiceUtilizator::update(int id, std::string newName, std::string newEmail, std::string newPass, int newLevel)
{
	Utilizator* u = new Utilizator(id, newName, newEmail, newPass, newLevel);
	UtilizatorValidator::validate(u);
	this->repo->update(this->repo->getById(id), u);
}

void ServiceUtilizator::remove(int id)
{
	this->repo->remove(this->repo->getById(id));
}

void ServiceUtilizator::update_clearance(int loggedInId, int actorId, int newLevel)
{
	Utilizator s = this->getUtilizatorById(loggedInId);
	Utilizator a = this->getUtilizatorById(actorId);
	if (s.getLevel() <= a.getLevel())
		throw std::runtime_error("Logged in user must have a strictly higher level.");
	else
		this->update(actorId, a.getName(), a.getEmail(), a.getPass(), newLevel);
}
