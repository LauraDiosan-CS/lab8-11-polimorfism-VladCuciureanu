#include <Employee.hpp>

Employee::Employee()
{
    this->name = nullptr;
    this->email = nullptr;
    this->clearanceLevel = 0;
}

Employee::Employee(unsigned int id, const char *name, const char *email, int clearanceLevel) : Entity(id)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = 0;
    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);
    this->email[strlen(email)] = 0;
    this->clearanceLevel = clearanceLevel;
}

Employee::Employee(const Employee &e)
{
    this->setId(e.entityId);
    this->name = new char[strlen(e.name) + 1];
    strcpy(this->name, e.name);
    this->name[strlen(e.name)] = 0;
    this->email = new char[strlen(e.email) + 1];
    strcpy(this->email, e.email);
    this->email[strlen(e.email)] = 0;
    this->clearanceLevel = e.clearanceLevel;
}

Employee::~Employee()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->email;
    this->email = nullptr;
    this->clearanceLevel = 0;
}

char* Employee::getName()
{
    return this->name;
}

char* Employee::getEmail()
{
    return this->email;
}

int Employee::getClearanceLevel()
{
    return this->clearanceLevel;
}

void Employee::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = 0;
}

void Employee::setEmail(const char* email)
{
    delete[] this->email;
    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);
    this->email[strlen(email)] = 0;
}
    
void Employee::setClearanceLevel(const int clearanceLevel)
{
    this->clearanceLevel = clearanceLevel;
}

void Employee::fromString(std::string info)
{
    int i1 = info.length()-1, i2 = info.length()-1;
	while (info[i1] != '|')
		i1--;
	this->setClearanceLevel(stod(info.substr(i1+1, i2-i1+1)));
	i1--;
	i2 = i1;
	while (info[i1] != '|')
		i1--;
	this->setEmail(info.substr(i1 + 1, i2 - i1).c_str());
	i1--;
	i2 = i1;
	while (info[i1] != '|')
		i1--;
	this->setName(info.substr(i1 + 1, i2 - i1).c_str());
	i2 = i1;
	i2--;
	i1 = 0;
	this->setId(stoi(info.substr(i1, i2-i1+1)));
}

Employee &Employee::operator=(const Employee &e)
{
    this->setId(e.entityId);
    this->name = new char[strlen(e.name) + 1];
    strcpy(this->name, e.name);
    this->name[strlen(e.name)] = 0;
    this->email = new char[strlen(e.email) + 1];
    strcpy(this->email, e.email);
    this->email[strlen(e.email)] = 0;
    this->clearanceLevel = e.clearanceLevel;
    return *this;
}

bool Employee::operator==(const Employee &s)
{
    if(this->getId()!=s.entityId)
        return false;
    if (strcmp(this->name, s.name) != 0)
        return false;
    if (strcmp(this->email, s.email) != 0)
        return false;
    if (this->clearanceLevel != s.clearanceLevel)
        return false;

    return true;
}

bool Employee::operator!=(const Employee &s)
{
    return !(this->operator==(s));
}

std::ostream &operator<<(std::ostream &os, const Employee &s)
{
    os << s.entityId << "|" << s.name << "|" << s.email << "|" << s.clearanceLevel;
    return os;
}