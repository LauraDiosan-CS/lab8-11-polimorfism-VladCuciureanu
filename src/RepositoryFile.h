#pragma once
#include "Entity.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "Repository.hpp"

using namespace std;

template <class T>
class RepositoryFile : public Repository<T>
{
protected:
	std::string fileName;

public:
	RepositoryFile()
	{
	}

	RepositoryFile(string fileName)
	{
		this->fileName = fileName;
	}

	~RepositoryFile()
	{
	}

	void setFileName(string fileName)
	{
		this->fileName = fileName;
	}

	void add(T *p)
	{
		Repository<T>::add(p);
		this->saveToFile();
	}

	void update(T *pVechi, T *pNou)
	{
		Repository<T>::update(pVechi, pNou);
		this->saveToFile();
	}

	void remove(int id)
	{
		Repository<T>::remove(id);
	}

	void remove(T *p)
	{
		Repository<T>::remove(p);
		this->saveToFile();
	}

	void emptyRepo()
	{
		Repository<T>::emptyRepo();
		this->saveToFile();
	}
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};
