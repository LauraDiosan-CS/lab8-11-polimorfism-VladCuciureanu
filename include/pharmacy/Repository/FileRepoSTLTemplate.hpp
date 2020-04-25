#pragma once
#include <RepoSTLTemplate.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

template <class T>
class FileRepoSTLTemplate : public RepoSTLTemplate<T>
{
private:
	char* fileName;

public:
	/*
	Blank constructor
	*/
	FileRepoSTLTemplate() {}

	/*
	Parameterized constructor
	*/
	FileRepoSTLTemplate(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy(this->fileName, fileName);
		this->fileName[strlen(fileName)] = 0;
		this->load();
	}

	/*
	Destructor
	*/
	~FileRepoSTLTemplate() {}

	/*
	Adds given object to repo.
	*/
	void addElem(T t)
	{
		RepoSTLTemplate<T>::addElem(t);
		this->save();
	}

	/*
	Updates object with given id with new values.
	*/
	void updateElem(unsigned int id, T update)
	{
		RepoSTLTemplate<T>::updateElem(id, update);
		this->save();
	}

	/*
	Deletes object with given id.
	*/
	void delElem(unsigned int id)
	{
		RepoSTLTemplate<T>::delElem(id);
		this->save();
	}

	/*
	Saves to file if filename provided in constructor.
	*/
	void save()
	{
		if (this->fileName == NULL)
			return;
		std::ofstream out(this->fileName);
		out << this->dim() << '\n';
		for (T t : this->getAll())
		{
			out << t << '\n';
		}
		out.close();
	}

	/*
	Loads from file if filename provided in constructor.
	*/
	void load()
	{
		try {
			if (this->fileName == NULL)
				return;
			std::ifstream in(this->fileName);
			int size;
			in >> size;
			in.get();
			for (int i = 0; i < size; i++)
			{
				T t;
				std::string inStr;
				getline(in, inStr);
				t.fromString(inStr);
				this->addElem(t);
			}
			in.close();
		}
		catch (int e) {
			std::cout << "Failed loading from file.\n";
		};
	}
};

