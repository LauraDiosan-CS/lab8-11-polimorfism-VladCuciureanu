#pragma once
#include "Entity.h"
#include <vector>

template <class T>
class Repository
{
protected:
	std::vector<T*> items; // Item storage vector
public:
	Repository(); // Constructor
	~Repository(); // Destructor

	std::vector<T*> getAll(); // Returns a vector of references to all items
	int getSize(); // Returns count of items in this repo
	T* getAtPos(int pos); // Returns a reference to the item at the given position inside the vector
	T* getById(int id); // Returns the object with the given id
	virtual void add(T* t); // Adds the referenced object to the vector
	virtual void update(T* tVechi, T* tNou); // Updates the referenced object with the values of the other referenced object.
	virtual void remove(int id); // Removes the object with the given id, if it exists.
	virtual void remove(T* t); // Removes the referenced object
	void emptyRepo(); // Clears the repo
};

template<class T>
inline Repository<T>::Repository()
{
}

template<class T>
inline Repository<T>::~Repository()
{
	this->items.clear();
}

template<class T>
inline std::vector<T*> Repository<T>::getAll()
{
	return this->items;
}

template<class T>
inline int Repository<T>::getSize()
{
	return this->items.size();
}

template<class T>
inline T* Repository<T>::getAtPos(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->items[pos]->clone();
	}
	throw "Invalid item position.";
}

template<class T>
inline T* Repository<T>::getById(int id)
{
	for (T* t : this->items)
	{
		if (t->getId() == id)
			return t;
	}
	throw "Couldn't find an entity with given ID.";
}

template<class T>
inline void Repository<T>::add(T* t)
{
	this->items.push_back(t->clone());
}

template<class T>
inline void Repository<T>::update(T* tVechi, T* tNou)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (*(this->items[i]) == *tVechi)
		{
			T* temp = this->items[i];
			delete temp;
			this->items[i] = tNou->clone();
			return;
		}
	}
	throw "Couldn't referenced entity in repo.";
}

template<class T>
inline void Repository<T>::remove(T* t)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (*(this->items[i]) == *t)
		{
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
			return;
		}
	}
	throw "Couldn't find referenced entity in repo.";
}

template<class T>
inline void Repository<T>::remove(int id)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if ((this->items.at(i))->getId() == id)
		{
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
			return;
		}
	}
	throw "Couldn't find an entity with given ID in repo.";
}

template<class T>
inline void Repository<T>::emptyRepo()
{
	for (int i = 0; i < this->items.size(); i++)
	{
		delete this->items[i];
	}
	this->items.clear();
}
