#pragma once
#include "RepositoryFile.h"

template <class T>
class RepositoryFileTXT : public RepositoryFile<T>
{
public:
	RepositoryFileTXT()
	{
	}

	RepositoryFileTXT(string fileName)
	{
		this->fileName = fileName;
	}

	~RepositoryFileTXT()
	{
	}

	void loadFromFile()
	{
		ifstream f(this->fileName);
		if (f.is_open())
		{
			this->emptyRepo();
			string linie;
			string delim = "|";
			while (getline(f, linie))
			{
				T* temp = new T();
				std::string f = linie;
				temp->fromString(f,'|');
				RepositoryFile<T>::add(temp);
			}
			f.close();
		}
	}

	void saveToFile()
	{
		ofstream f(this->fileName);
		if (f.is_open())
		{
			for (Entity *elem : this->elems)
			{
				f << elem->toString("|") << endl;
			}
		}
	}
};