#pragma once
#include "RepositoryFile.h"

template <class T>
class RepositoryFileCSV : public RepositoryFile<T>
{
public:
	RepositoryFileCSV() : RepositoryFile()
	{
	}

	RepositoryFileCSV(string fileName) : RepositoryFile(fileName)
	{
	}

	~RepositoryFileCSV()
	{
	}

	void loadFromFile()
	{
		ifstream f(this->fileName);
		if (f.is_open())
		{
			this->emptyRepo();
			string linie;
			string delim = ",";
			while (getline(f, linie))
			{
				RepositoryFile<T>::add(T.fromString(linie));
			}
			f.close();
		}
	}

	void saveToFile()
	{
		ofstream f(this->fileName);
		if (f.is_open())
		{
			for (Produs *elem : this->elems)
			{
				f << elem->toString(",") << endl;
			}
		}
	}
};