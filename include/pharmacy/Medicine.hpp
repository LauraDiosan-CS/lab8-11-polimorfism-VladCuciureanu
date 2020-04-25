#include <Entity.hpp>

class Medicine : public Entity
{
private:
    char *name;
    bool prescription;
    unsigned int stockCount;
    char *brand;

public:
    //Blank constructor
    Medicine();

    //Parameterized constructor
    Medicine(unsigned int id, const char *name, bool prescription, unsigned int stockCount, const char *brand);

    //Copy constructor
    Medicine(const Medicine &m);

    //Destructor
    ~Medicine();

    //Name getter
    char *getName();

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

    //Parses medicine object from string
    void fromString(std::string info);

    //Copy operator
    Medicine &operator=(const Medicine &s);

    //Equals operator
    bool operator==(const Medicine &s);

    //Not equals operator
    bool operator!=(const Medicine &s);

    //Serializer
    friend std::ostream &operator<<(std::ostream &os, const Medicine &s);
};