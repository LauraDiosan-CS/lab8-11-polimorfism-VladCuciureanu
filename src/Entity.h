#pragma once
#include <iostream>
#include <string>
class Entity
{
protected:
	int id; // Entity Id
public:
	Entity(); // Blank constructor
	Entity(int id); // Parameterized constructor
	Entity(const Entity& e); // Copy constructor
	virtual ~Entity(); // Destructor

	virtual Entity* clone(); // Clone object

	int getId(); // Id getter
	void setId(int id); // Id setter
	Entity& operator=(const Entity& e); // Copy operator
	bool operator==(const Entity& e); // Equals operator
	bool operator!=(const Entity& e); // NEquals operator

	virtual std::string toString(std::string delimitator); // Serializer
	static Entity& fromString(std::string delimitator, std::string rawText); // Deserializer
};
