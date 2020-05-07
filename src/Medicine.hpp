#include <Entity.hpp>

class Medicament : public Entity
{
private:
    char *name;
    bool prescription;
    unsigned int stockCount;
    char *brand;

public:
    //Blank constructor
    Medicament();

    //Parameterized constructor
    Medicament(unsigned int id, const char *name, bool prescription, unsigned int stockCount, const char *brand);

    //Copy constructor
    Medicament(const Medicament &m);

    //Destructor
    ~Medicament();

    //Name getter
    char *getName();

    int getId();
    //Prescription requirement getter
    bool getPrescriptionRequirement();

    //Stock count getter
    unsigned int getStockCount();

    //Brand getter
    char *getBrand();

    //Name setter
    void setName(const char *name);

    //Prescription requirement setter
    void setPrescriptionRequirement(bool value);

    //Stock count setter
    void setStockCount(unsigned int stockCount);

    //Brand setter
    void setBrand(const char *brand);

    std::string toString(char separator);

    //Parses medicine object from string
    void fromString(std::string info, char separator);

    //Copy operator
    Medicament &operator=(const Medicament &s);

    //Equals operator
    bool operator==(const Medicament &s);

    //Not equals operator
    bool operator!=(const Medicament &s);

    //Serializer
    friend std::ostream &operator<<(std::ostream &os, const Medicament &s);

    Medicament* clone();
};