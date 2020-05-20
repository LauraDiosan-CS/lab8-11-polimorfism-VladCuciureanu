#include "MedicineValidator.h"

void MedicineValidator::validate(Medicament* m)
{
	if (m->getId() < 0)
		throw "Medicine ID must be greater or equal to 0.";
	if (m->getName() == "")
		throw "Medicine name must not be empty.";
	if (m->getStock() < 0)
		throw "Medicine stock count must be greater or equal to 0.";
	if (m->getBrand() == "")
		throw "Medicine brand name must not be empty.";
}
