#pragma once
#include <iostream>
#include <string.h>

class Entity
{
public:
	unsigned int entityId;
	Entity()
	{
		this->entityId = 0;
	}
	Entity(unsigned int id);
	Entity(const Entity &e);
	Entity *clone();
	virtual ~Entity();
	unsigned int getId();
	void setId(unsigned int id);
	Entity& operator=(const Entity& p);
	bool operator==(const Entity &p);
	std::string toString(std::string delim);
};