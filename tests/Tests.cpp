#include <Medicine.hpp>
#include <Employee.hpp>
#include <RepoSTLTemplate.hpp>
#include <FileRepoSTLTemplate.hpp>
#include <assert.h>
#include <iostream>

int main()
{
    //Domain testing
    //Medicine:
    Medicine md1(0, "a", false, 1, "b");
    Medicine md2 = md1;
    md2.fromString("0|a|false|1|b");
    assert(md1 == md2);
    md2.setId(1);
    md2.setName("bb");
    md2.setPrescriptionRequirement(true);
    md2.setStockCount(3);
    md2.setBrand("ccc");
    assert(md2.getId() == 1);
    assert(strcmp(md2.getName(), "bb") == 0);
    assert(md2.getPrescriptionRequirement());
    assert(md2.getStockCount() == 3);
    assert(strcmp(md2.getBrand(), "ccc") == 0);
    assert(md1 != md2);
    //Employees:
    Employee ed1(0, "vlad", "vlad", 9);
    Employee ed2 = ed1;
    ed2.fromString("0|vlad|vlad|9");
    assert(ed1==ed2);
    ed2.setId(1);
    ed2.setName("test");
    ed2.setEmail("best");
    ed2.setClearanceLevel(8);
    assert(ed2.getId()==1);
    assert(strcmp(ed2.getName(),"test")==0);
    assert(strcmp(ed2.getEmail(), "best")==0);
    assert(ed2.getClearanceLevel()==8);
    assert(ed1!=ed2);

    //Repo testing
    //Medicine:
    FileRepoSTLTemplate<Medicine> medicineRepo("test_medicine.txt");
    //RepoSTLTemplate<Medicine> medicineRepo;
    Medicine m1(medicineRepo.getFreeId(), "Xanax", true, 23, "SpaceXlmao");
    medicineRepo.addElem(m1);
    Medicine m2(medicineRepo.getFreeId(), "Hydroxychloroquine", true, 1, "Orange");
    medicineRepo.addElem(m2);
    Medicine m3(medicineRepo.getFreeId(), "Azytromicin", true, 14, "A-Z");
    medicineRepo.addElem(m3);
    Medicine m4(medicineRepo.getFreeId(), "Coldrex", false, 200, "Fervex???");
    medicineRepo.addElem(m4);
    //Employees:
    FileRepoSTLTemplate<Employee> employeeRepo("test_employees.txt");
    //RepoSTLTemplate<Employee> employeeRepo;
    Employee e1(employeeRepo.getFreeId(), "Vlad", "test@gmail.com", 9);
    employeeRepo.addElem(e1);
    Employee e2(employeeRepo.getFreeId(), "Cornel", "cornel@mail.com", 8);
    employeeRepo.addElem(e2);
    Employee e3(employeeRepo.getFreeId(), "testname", "whoevenusesyahooanymore@yahoo.com", 7);
    employeeRepo.addElem(e3);
    Employee e4(employeeRepo.getFreeId(), "washyohands", "stayhome@protonmail.com", 1);
    employeeRepo.addElem(e4);
    assert(employeeRepo.dim() == 4);
    employeeRepo.delElem(3);
    assert(employeeRepo.dim() == 3);
    assert(*employeeRepo.findElemById(0) == e1);
    //Loading and saving
    //Medicine:
    std::ifstream in("test_medicine.txt");
    int n;
    in >> n;
    assert(n == 4);
    std::string s;
    in.get();
    getline(in, s);
    assert(s == "0|Xanax|true|23|SpaceXlmao");
    getline(in, s);
    assert(s == "1|Hydroxychloroquine|true|1|Orange");
    getline(in, s);
    assert(s == "2|Azytromicin|true|14|A-Z");
    getline(in, s);
    assert(s == "3|Coldrex|false|200|Fervex???");
    in.close();
    if (remove("test_medicine.txt") != 0)
        perror("Error deleting file test_medicine.txt");
    else
        puts("File successfully deleted");
    //Employees:
    std::ifstream in2("test_employees.txt");
    int n2;
    in2 >> n2;
    assert(n2 == 3);
    std::string s2;
    in2.get();
    getline(in2, s2);
    assert(s2 == "0|Vlad|test@gmail.com|9");
    getline(in2, s2);
    assert(s2 == "1|Cornel|cornel@mail.com|8");
    getline(in2, s2);
    assert(s2 == "2|testname|whoevenusesyahooanymore@yahoo.com|7");
    //getline(in2, s2);
    //assert(s=="3|washyohands|stayhome@protonmail.com|1");
    in2.close();
    if (remove("test_employees.txt") != 0)
        perror("Error deleting file test_employees.txt");
    else
        puts("File successfully deleted");

    std::cout << "Passed all tests successfully!";
    return 0;
}
