//TODO: REMOVE THESE
#include <Medicine.hpp>
#include <Employee.hpp>
#include <FileRepoSTLTemplate.hpp>
#include <RepoSTLTemplate.hpp>
#include <vector>
//TODO: REMOVE ABOVE

int main(int argc, char** argv)
{
    //FileRepoSTLTemplate<Employee> employeeRepo("employees.txt");
    RepoSTLTemplate<Employee> employeeRepo;
    Employee e1(employeeRepo.getFreeId(), "Vlad", "test@gmail.com", 9);
    employeeRepo.addElem(e1);
    Employee e2(employeeRepo.getFreeId(), "Cornel", "cornel@mail.com", 8);
    employeeRepo.addElem(e2);
    Employee e3(employeeRepo.getFreeId(), "testname", "whoevenusesyahooanymore@yahoo.com", 7);
    employeeRepo.addElem(e3);
    Employee e4(employeeRepo.getFreeId(), "washyohands", "stayhome@protonmail.com", 1);
    employeeRepo.addElem(e4);
    for(int i=0; i<4; i++)
    {
        std::cout<<*(employeeRepo.findElemById(i))<<std::endl;
    }

    //FileRepoSTLTemplate<Medicine> medicineRepo("medicine.txt");
    RepoSTLTemplate<Medicine> medicineRepo;
    Medicine m1(medicineRepo.getFreeId(), "Xanax", true, 23, "SpaceXlmao");
    medicineRepo.addElem(m1);
    Medicine m2(medicineRepo.getFreeId(), "Hydroxychloroquine", true, 1, "Orange");
    medicineRepo.addElem(m2);
    Medicine m3(medicineRepo.getFreeId(), "Azytromicin", true, 14, "A-Z");
    medicineRepo.addElem(m3);
    Medicine m4(medicineRepo.getFreeId(), "Coldrex", false, 200, "Fervex???");
    medicineRepo.addElem(m4);
    for(int i=0; i<4; i++)
    {
        std::cout<<*(medicineRepo.findElemById(i))<<std::endl;
    }
    return 0;
}