#pragma once
#include <vector>
#include <algorithm>
#include <Entity.hpp>

template <class T>
class RepoSTLTemplate
{
private:
	std::vector<T> elem; // Objects vector.
	unsigned int idCounter = 0;
public:

	/*
	Blank constructor
	*/
	RepoSTLTemplate() {
		static_assert(std::is_base_of<Entity, T>::value, "Derived not derived from BaseClass");
	}

	/*
	Destructor
	*/
	~RepoSTLTemplate() {}

	/*
	Adds given object to the repo.
	In: given object.
	*/
	virtual void addElem(T t) {
		int id = ((Entity)t).getId();
		if (findElemById(id) != this->elem.end())
			return; // TODO: throw error due to entity id being already taken.
		this->elem.push_back(t);
		idCounter++;
	}

	/*
	Returns the first iterator whose entity ID is equal to the one provided by user.
	In: provided entity ID.
	Out: iterator of object.
	*/
	typename std::vector<T>::iterator findElemById(const int entityId) {
		typename std::vector<T>::iterator it;
		it = find_if(this->elem.begin(), this->elem.end(), [entityId](T t) { return ((Entity)t).getId() == entityId; });
		return it;
	}

	/*
	Returns all objects in repo.
	Out: vector of all objects.
	*/
	std::vector<T> getAll()
	{
		return this->elem;
	}

	/*
	Finds object with given id and replaces it's values with given object's values.
	In: given id
	In: object with new values
	*/
	virtual void updateElem(unsigned int id, T update)
	{
		typename std::vector<T>::iterator it;
		it = findElemById(id);
		*it = update;
	}

	/*
	Deletes object with given id.
	In: given id.
	*/
	virtual void delElem(unsigned int id)
	{
		typename std::vector<T>::iterator it;
		it = findElemById(id);
		this->elem.erase(it);
	}

	/*
	Returns an iterator to the end element of the repo.
	Out: end iterator.
	*/
	typename std::vector<T>::iterator getEnd()
	{
		return this->elem.end();
	}

	/*
	Returns the size of the repo.
	Out: repo size.
	*/
	unsigned int dim()
	{
		return this->elem.size();
	}

	/*
	Returns free ID.
	Out: free id.
	*/
	unsigned int getFreeId()
	{
		return this->idCounter;
	}
};