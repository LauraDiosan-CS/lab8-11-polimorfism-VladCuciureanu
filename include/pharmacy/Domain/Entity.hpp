#pragma once
#include <iostream>
#include <string.h>

class Entity
{
protected:
	unsigned int entityId;
public:
	Entity();
	Entity(unsigned int id);
	Entity(const Entity& e);
	virtual ~Entity();
	unsigned int getId();
	void setId(unsigned int id);
};