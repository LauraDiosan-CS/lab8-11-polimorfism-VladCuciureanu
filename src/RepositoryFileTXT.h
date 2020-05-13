#pragma once
#include <fstream>
#include "RepositoryFile.h"

template <class T>
class RepositoryFileTXT : public RepositoryFile<T>
{
public:
	RepositoryFileTXT() // Blank constructor
	{

	}
	RepositoryFileTXT(std::string fileName) : RepositoryFile<T>(fileName) // Parameterized constructor
	{
		this->loadFromFile();
	}
	~RepositoryFileTXT() // Destructor
	{
	}
	void loadFromFile() override // Loads objects from file
	{
		std::ifstream f(this->fileName);
		if (f.is_open())
		{
			this->emptyRepo();
			std::string linie;
			std::string delimitator = "|";
			while (getline(f, linie))
			{
				this->add(T::fromString("|", linie));
			}
			f.close();
		}
	}
	void saveToFile() override // Saves objects to file
	{
		std::ofstream f(this->fileName);
		if (f.is_open())
		{
			for (Entity* elem : this->items)
			{
				f << elem->toString("|") << std::endl;
			}
		}
	}
};