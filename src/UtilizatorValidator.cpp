#include "UtilizatorValidator.h"

void UtilizatorValidator::validate(Utilizator* u)
{
	if (u->getId() < 0)
	{
		throw "User ID must be greater or equal to 0.";
	}
	if (u->getName() == "")
		throw "User name must not be blank.";
	if (u->getLevel() < 0)
		throw "User clearance level must be greater or equal to 0.";
	if (u->getEmail() == "")
		throw "User email must not be blank.";
}
