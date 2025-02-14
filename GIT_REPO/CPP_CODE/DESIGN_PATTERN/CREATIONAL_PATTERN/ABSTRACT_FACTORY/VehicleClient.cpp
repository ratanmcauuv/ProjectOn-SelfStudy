#include <iostream>
#include <typeinfo>
#include <string>
#include "AutoMobileFactory.h"
#include "AbsVehicleFactory.h"
using namespace std;

//Client
int main()
{
    string vCompany;
    std::cout << "Enter vehicle Company to be created : \n";
    std::cin >> vCompany;

    AbsVehicleFactory *absFactory = AutoMobileFactory :: GetVehicleFactory(vCompany);
    if(absFactory) {
        std::cout << "Type of absFactory ::: " << typeid(absFactory).name() << std::endl;
        absFactory->getFactoryName();
        absFactory->createCar();
    }    
    
    return 0;
}