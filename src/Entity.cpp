#include "Entity.h"

Entity::Entity()
{
	this->id = 0;
}
Entity::Entity(int id)
{
	this->id = id;
}
Entity::Entity(const Entity& e)
{
	this->id = e.id;
}
Entity::~Entity()
{
}

Entity* Entity::clone()
{
	return new Entity(this->id);
}

int Entity::getId()
{
	return this->id;
}
void Entity::setId(int id)
{
	this->id = id;
}
Entity& Entity::operator=(const Entity& e)
{
	this->id = e.id;
	return *this;
}
bool Entity::operator==(const Entity& e)
{
	if (this->id != e.id)
		return false;
	return true;
}
bool Entity::operator!=(const Entity& e)
{
	return !(operator==(e));
}

std::string Entity::toString(std::string delimitator)
{
	return std::to_string(this->id);
}

Entity& Entity::fromString(std::string delimitator, std::string rawText)
{
	Entity* e = new Entity();
	try {
		e->setId(std::stoi(rawText));
	}
	catch(std::string error)
	{
		throw "Invalid serialized Entity string.";
	}
}
