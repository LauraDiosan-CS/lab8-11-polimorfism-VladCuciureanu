#pragma once
#include "Entity.h"
class Medicament : public Entity
{
protected:
	std::string name; // Medicine name
	bool prescription; // Does this medicine need a prescription?
	int stock; // Count of this medicine in stock
	std::string brand; // Medicine brand
public:
	Medicament(); // Blank constructor
	Medicament(int id, std::string name, bool prescription, int stock, std::string brand); // Parameterized constructor
	Medicament(const Medicament& u); // Copy constructor
	virtual ~Medicament(); // Destructor

	Medicament* clone(); // Clone object

	std::string getName(); // Name getter
	bool getPrescription(); // Prescription flag getter
	int getStock(); // Stock getter
	std::string getBrand(); // Brand getter

	void setName(std::string name); // Name setter
	void setPrescription(bool value); // Prescription flag setter
	void setStock(int stock); // Stock setter
	void setBrand(std::string brand); // Brand setter

	Medicament& operator=(const Medicament& e); // Copy operator
	bool operator==(const Medicament& e); // Equals operator
	bool operator!=(const Medicament& e); // NEquals operator

	std::string toString(std::string delimitator); // Serializer
	static Medicament* fromString(std::string delimitator, std::string rawText); // Deserializer
};
