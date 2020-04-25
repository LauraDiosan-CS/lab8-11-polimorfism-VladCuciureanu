#include <Entity.hpp>

Entity::Entity()
{
	this->entityId = 0;
}

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

void Entity::setId(unsigned int id)
{
	this->entityId = id;
}