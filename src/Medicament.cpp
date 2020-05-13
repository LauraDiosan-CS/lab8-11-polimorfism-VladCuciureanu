#include "Medicament.h"

Medicament::Medicament() : Entity(0)
{
	this->name = "";
	this->prescription = false;
	this->stock = 0;
	this->brand = "";
}
Medicament::Medicament(int id, std::string name, bool prescription, int stock, std::string brand) : Entity(id)
{
	this->name = name;
	this->prescription = prescription;
	this->stock = stock;
	this->brand = brand;
}
Medicament::Medicament(const Medicament& u)
{
	this->id = u.id;
	this->name = u.name;
	this->prescription = u.prescription;
	this->stock = u.stock;
	this->brand = u.brand;
}
Medicament::~Medicament()
{
}

Medicament* Medicament::clone()
{
	return new Medicament(this->id, this->name, this->prescription, this->stock, this->brand);
}

std::string Medicament::getName()
{
	return this->name;
}
bool Medicament::getPrescription()
{
	return this->prescription;
}
int Medicament::getStock()
{
	return this->stock;
}
std::string Medicament::getBrand()
{
	return this->brand;
}

void Medicament::setName(std::string name)
{
	this->name = name;
}
void Medicament::setPrescription(bool value)
{
	this->prescription = value;
}
void Medicament::setStock(int stock)
{
	this->stock = stock;
}
void Medicament::setBrand(std::string brand)
{
	this->brand = brand;
}

Medicament& Medicament::operator=(const Medicament& e)
{
	this->id = e.id;
	this->name = e.name;
	this->prescription = e.prescription;
	this->brand = e.brand;
	return *this;
}

bool Medicament::operator==(const Medicament& e)
{
	if (this->id != e.id)
		return false;
	if (this->name != e.name)
		return false;
	if (this->prescription != e.prescription)
		return false;
	if (this->stock != e.stock)
		return false;
	if (this->brand != e.brand)
		return false;
	return true;
}

bool Medicament::operator!=(const Medicament& e)
{
	return !(operator==(e));
}

std::string Medicament::toString(std::string delimitator)
{
	return std::to_string(this->id) + delimitator + this->name + delimitator + (this->prescription ? "true" : "false") + delimitator + std::to_string(this->stock) + delimitator + this->brand;
}

Medicament* Medicament::fromString(std::string delimitator, std::string rawText)
{
	try {
		int poz = rawText.find(delimitator);
		int id = std::stoi(rawText.substr(0, poz));
		rawText = rawText.erase(0, poz + 1);

		poz = rawText.find(delimitator);
		std::string name = rawText.substr(0, poz);
		rawText = rawText.erase(0, poz + 1);

		poz = rawText.find(delimitator);
		bool prescription = rawText.substr(0, poz) == "true";
		rawText = rawText.erase(0, poz + 1);

		poz = rawText.find(delimitator);
		int stock = std::stoi(rawText.substr(0, poz));
		rawText = rawText.erase(0, poz + 1);

		std::string brand = rawText;

		return new Medicament(id, name, prescription, stock, brand);
	}
	catch (std::string error)
	{
		throw "Invalid serialized Medicament string.";
	}
}