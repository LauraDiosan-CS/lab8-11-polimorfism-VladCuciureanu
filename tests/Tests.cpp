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
    Medicine m1(0, "a", false, 1, "b");
    Medicine m2=m1;
    m2.fromString("0|a|false|1|b");
    assert(m1==m2);
    m2.setId(1);
    m2.setName("bb");
    m2.setPrescriptionRequirement(true);
    m2.setStockCount(3);
    m2.setBrand("ccc");
    assert(m2.getId()==1);
    assert(strcmp(m2.getName(),"bb")==0);
    assert(m2.getPrescriptionRequirement());
    assert(m2.getStockCount()==3);
    assert(strcmp(m2.getBrand(),"ccc")==0);
    assert(m1!=m2);

    std::cout<<"Passed all tests successfully!";
    return 0;
}
