#include <Medicine.hpp>

Medicine::Medicine()
{
    this->name = nullptr;
    this->prescription = false;
    this->stockCount = 0;
    this->brand = nullptr;
}

Medicine::Medicine(unsigned int id, const char *name, bool prescription, unsigned int stockCount, const char *brand)
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

Medicine::Medicine(const Medicine &m)
{
    this->operator=(m);
}

Medicine::~Medicine()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->brand;
    this->brand = nullptr;
}

char *Medicine::getName() { return this->name; }

bool Medicine::getPrescriptionRequirement() { return this->prescription; }

unsigned int Medicine::getStockCount() { return this->stockCount; }

char *Medicine::getBrand() { return this->brand; }

void Medicine::setName(const char *name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = 0;
}

void Medicine::setPrescriptionRequirement(bool value)
{
    this->prescription = value;
}

void Medicine::setStockCount(unsigned int stockCount)
{
    this->stockCount = stockCount;
}

void Medicine::setBrand(const char *brand)
{
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->brand[strlen(brand)] = 0;
}

void Medicine::fromString(std::string info)
{
}

Medicine &Medicine::operator=(const Medicine &s)
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

bool Medicine::operator==(const Medicine &s)
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

bool Medicine::operator!=(const Medicine &s) { return !(this->operator==(s)); }

std::ostream &operator<<(std::ostream &os, const Medicine &s)
{
    os << s.entityId << "|" << s.name << "|" << s.prescription << "|" << s.stockCount << "|" << s.brand;
    return os;
}