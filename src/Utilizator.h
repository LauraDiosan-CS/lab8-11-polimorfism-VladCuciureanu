#pragma once
#include "Entity.h"
class Utilizator : public Entity
{
protected:
	std::string name; // User name
	std::string email; // User email
	std::string pass;
	int level; // User clearance level
public:
	Utilizator(); // Blank constructor
	Utilizator(int id, std::string name, std::string email, std::string pass, int level); // Parameterized constructor
	Utilizator(const Utilizator& u); // Copy constructor
	~Utilizator(); // Destructor 
	Utilizator* clone(); // Clones the object
	std::string getName(); // Name getter
	std::string getEmail(); // Email getter
	std::string getPass();
	int getLevel(); // Clearance level getter
	void setName(std::string name); // Name setter
	void setEmail(std::string email); // Email setter
	void setPass(std::string pass);
	void setLevel(int level); // Clearance level setter
	Utilizator& operator=(const Utilizator& e); // Copy operator
	bool operator==(const Utilizator& e); // Equals operator
	bool operator!=(const Utilizator& e); // NEquals operator

	std::string toString(std::string delimitator); // Serializer
	static Utilizator* fromString(std::string delimitator, std::string rawText); // Deserializer
};
