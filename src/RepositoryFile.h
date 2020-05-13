#pragma once
#include "Repository.h"

template <class T>
class RepositoryFile : public Repository<T>
{
protected:
	std::string fileName; // Repo file name
public:
	RepositoryFile() // Blank constructor
	{
	}
	RepositoryFile(std::string fileName) // Parameterized constructor
	{
		this->fileName = fileName;
	}
	~RepositoryFile() // Destructor
	{
	}

	void setFileName(std::string fileName) // File name setter
	{
		this->fileName = fileName;
	}

	virtual void add(T* t) override // Add referenced object to repo
	{
		Repository<T>::add(t);
		this->saveToFile();
	}

	virtual void update(T* tVechi, T* tNou) override // Updates referenced object with the values of the second referenced object
	{
		Repository<T>::update(tVechi, tNou);
		this->saveToFile();
	}

	virtual void remove(int id) override // Removes the object with the given id from the repo
	{
		Repository<T>::remove(id);
		this->saveToFile();
	}

	virtual void remove(T* t) override // Removes the referenced object from the repo
	{
		Repository<T>::remove(t);
		this->saveToFile();
	}

	virtual void loadFromFile() = 0	;
	virtual void saveToFile() = 0;
};