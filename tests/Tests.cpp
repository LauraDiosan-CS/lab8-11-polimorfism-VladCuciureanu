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
    std::cout<<"neee";
    Medicine m2=m1;
    std::cout<<"neee";
    m2.fromString("0|a|false|1|b");
    std::cout<<"neee";
    assert(m1==m2);
    std::cout<<"neee";
    m2.setId(1);
    std::cout<<"neee";
    m2.setName("bb");
    m2.setPrescriptionRequirement(true);
    m2.setStockCount(3);
    m2.setBrand("ccc");
    assert(m2.getId()==1);
    std::cout<<m2.getName();
    //assert(m2.getName()=="bb");
    assert(m2.getPrescriptionRequirement());
    assert(m2.getStockCount()==3);
    assert(m2.getBrand()=="ccc");
    assert(m1!=m2);


    std::cout<<"Passed all tests successfully!";
    return 0;
}
