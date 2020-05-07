#include <Medicine.hpp>
#include <string>

Medicament::Medicament()
{
    this->name = nullptr;
    this->prescription = false;
    this->stockCount = 0;
    this->brand = nullptr;
}

Medicament::Medicament(unsigned int id, const char *name, bool prescription, unsigned int stockCount, const char *brand)
{
    this->setId(id);
    this->setPrescriptionRequirement(prescription);
    this->setStockCount(stockCount);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = 0;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->brand[strlen(brand)] = 0;
}

Medicament::Medicament(const Medicament &m)
{
    this->operator=(m);
}

Medicament::~Medicament()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->brand;
    this->brand = nullptr;
}

char *Medicament::getName() { return this->name; }

bool Medicament::getPrescriptionRequirement() { return this->prescription; }

unsigned int Medicament::getStockCount() { return this->stockCount; }

char *Medicament::getBrand() { return this->brand; }

void Medicament::setName(const char *name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = 0;
}

void Medicament::setPrescriptionRequirement(bool value)
{
    this->prescription = value;
}

void Medicament::setStockCount(unsigned int stockCount)
{
    this->stockCount = stockCount;
}

void Medicament::setBrand(const char *brand)
{
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->brand[strlen(brand)] = 0;
}

std::string Medicament::toString(char separator)
{
    std::string output = "";
    output += std::to_string(this->entityId);
    output += separator;
    output += std::string(this->name);
    output += separator;
    if (this->prescription)
        output += "true";
    else
        output += "false";
    output += separator;
    output += std::to_string(this->stockCount);
    output += separator;
    output += std::string(this->brand);
    return output;
}

void Medicament::fromString(std::string info, char separator)
{
    int i1 = info.length() - 1, i2 = info.length() - 1;
    while (info[i1] != separator)
        i1--;
    this->setBrand(info.substr(i1 + 1, i2 - i1).c_str());
    i1--;
    i2 = i1;
    while (info[i1] != separator)
        i1--;
    this->setStockCount(stod(info.substr(i1 + 1, i2 - i1 + 1)));
    i1--;
    i2 = i1;
    while (info[i1] != separator)
        i1--;
    this->setPrescriptionRequirement(info.substr(i1 + 1, i2 - i1).c_str() == "true");
    i1--;
    i2 = i1;
    while (info[i1] != separator)
        i1--;
    this->setName(info.substr(i1 + 1, i2 - i1).c_str());
    i2 = i1;
    i2--;
    i1 = 0;
    this->setId(stoi(info.substr(i1, i2 - i1 + 1)));
}

Medicament &Medicament::operator=(const Medicament &s)
{
    this->setId(s.entityId);
    this->name = new char[strlen(s.name) + 1];
    strcpy(this->name, s.name);
    this->name[strlen(s.name)] = 0;
    this->brand = new char[strlen(s.brand) + 1];
    strcpy(this->brand, s.brand);
    this->brand[strlen(s.brand)] = 0;
    this->setPrescriptionRequirement(s.prescription);
    this->setStockCount(s.stockCount);

    return *this;
}

int Medicament::getId()
{
    return this->entityId;
}

bool Medicament::operator==(const Medicament &s)
{
    if (this->entityId != s.entityId)
        return false;
    if (strcmp(this->name, s.name) != 0)
        return false;
    if (strcmp(this->brand, s.brand) != 0)
        return false;
    if (this->stockCount != s.stockCount)
        return false;
    if (this->prescription != s.prescription)
        return false;

    return true;
}

bool Medicament::operator!=(const Medicament &s) { return !(this->operator==(s)); }

std::ostream &operator<<(std::ostream &os, const Medicament &s)
{
    os << s.entityId << "|" << s.name << "|";
    if (s.prescription)
        os << "true";
    else
        os << "false";
    os << "|" << s.stockCount << "|" << s.brand;
    return os;
}

Medicament* Medicament::clone()
{
	return new Medicament(this->entityId, this->name, this->prescription, this->stockCount, this->brand);
}