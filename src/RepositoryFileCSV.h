#pragma once
#include <fstream>
#include "RepositoryFile.h"

template <class T>
class RepositoryFileCSV : public RepositoryFile<T>
{
public:
	RepositoryFileCSV() // Blank constructor
	{

	}
	RepositoryFileCSV(std::string fileName) : RepositoryFile<T>(fileName) // Parameterized constructor
	{
		this->loadFromFile();
	}
	~RepositoryFileCSV() // Destructor
	{
	}
	void loadFromFile() override // Load objects from file
	{
		std::ifstream f(this->fileName);
		if (f.is_open())
		{
			this->emptyRepo();
			std::string linie;
			std::string delimitator = ",";
			while (getline(f, linie))
			{
				this->add(T::fromString(",", linie));
			}
			f.close();
		}
	}
	void saveToFile() override // Save objects to file
	{
		std::ofstream f(this->fileName);
		if (f.is_open())
		{
			for (Entity* elem : this->items)
			{
				f << elem->toString(",") << std::endl;
			}
		}
	}
};