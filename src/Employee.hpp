#include <Entity.hpp>

class Employee : public Entity
{
private:
    char *name;
    char *email;
    int clearanceLevel;
public:
    //Blank constructor
    Employee();

    //Parameterized constructor
    Employee(unsigned int id, const char *name, const char *email, int clearanceLevel);

    //Copy constructor
    Employee(const Employee& e);

    //Destructor
    ~Employee();

    //Name getter
    char* getName();

    //Email getter
    char* getEmail();
    
    //Clearance level getter
    int getClearanceLevel();

    //Name setter
    void setName(const char* name);

    //Email setter
    void setEmail(const char* email);
    
    //Clearance level setter
    void setClearanceLevel(const int clearanceLevel);

    //Parses employee object from string
	void fromString(std::string info, char separator);

    std::string toString(char separator);

	//Copy operator
	Employee& operator=(const Employee& s);
	
	//Equals operator
	bool operator==(const Employee& s);

	//Not equals operator
	bool operator!=(const Employee& s);

    //Serializer
	friend std::ostream& operator<<(std::ostream& os, const Employee& s);

    Employee* clone();
};