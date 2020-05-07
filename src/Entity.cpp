#include <Entity.hpp>
#include <string>

Entity::Entity(unsigned int id)
{
	this->entityId = id;
}

Entity::Entity(const Entity& e)
{
	this->entityId = e.entityId;
}

Entity::~Entity() {}

unsigned int Entity::getId()
{
	return this->entityId;
}

Entity* Entity::clone()
{
	return new Entity(this->entityId);
}

void Entity::setId(unsigned int id)
{
	this->entityId = id;
}

Entity& Entity::operator=(const Entity& p)
{
	this->entityId = p.entityId;
	return *this;
}

bool Entity::operator==(const Entity& p)
{
	return this->entityId == p.entityId;
}

std::string Entity::toString(std::string delim)
{
	return std::to_string(this->entityId);
}
