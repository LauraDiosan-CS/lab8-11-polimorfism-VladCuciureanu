#include "Utilizator.h"

Utilizator::Utilizator() : Entity(0)
{
	this->name = "";
	this->email = "";
	this->level = 0;
}
Utilizator::Utilizator(int id, std::string name, std::string email, int level) : Entity(id)
{
	this->name = name;
	this->email = email;
	this->level = level;
}
Utilizator::Utilizator(const Utilizator& u) : Entity(u.id)
{
	this->name = u.name;
	this->email = u.email;
	this->level = u.level;
}
Utilizator::~Utilizator()
{
}
Utilizator* Utilizator::clone()
{
	return new Utilizator(this->id, this->name, this->email, this->level);
}
std::string Utilizator::getName()
{
	return this->name;
}
std::string Utilizator::getEmail()
{
	return this->email;
}
int Utilizator::getLevel()
{
	return this->level;
}
void Utilizator::setName(std::string name)
{
	this->name = name;
}
void Utilizator::setEmail(std::string email)
{
	this->email = email;
}
void Utilizator::setLevel(int level)
{
	this->level = level;
}
Utilizator& Utilizator::operator=(const Utilizator& e)
{
	this->id = e.id;
	this->name = e.name;
	this->email = e.email;
	this->level = e.level;
	return *this;
}
bool Utilizator::operator==(const Utilizator& e)
{
	if (this->id != e.id)
		return false;
	if (this->name != e.name)
		return false;
	if (this->email != e.email)
		return false;
	if (this->level != e.level)
		return false;
	return true;
}
bool Utilizator::operator!=(const Utilizator& e)
{
	return !(operator==(e));
}

std::string Utilizator::toString(std::string delimitator)
{
	return std::to_string(this->id) + delimitator + this->name + delimitator + this->email + delimitator + std::to_string(this->level);
}

Utilizator* Utilizator::fromString(std::string delimitator, std::string rawText)
{
	try {
		int poz = rawText.find(delimitator);
		int id = std::stoi(rawText.substr(0, poz));
		rawText = rawText.erase(0, poz + 1);

		poz = rawText.find(delimitator);
		std::string name = rawText.substr(0, poz);
		rawText = rawText.erase(0, poz + 1);

		poz = rawText.find(delimitator);
		std::string email = rawText.substr(0, poz);
		rawText = rawText.erase(0, poz + 1);

		int level = std::stoi(rawText);

		return new Utilizator(id, name, email, level);
	}
	catch (std::string error)
	{
		throw "Invalid serialized Utilizator string.";
	}
}
