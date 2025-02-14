#ifndef __MAHINDRA_H__
#define __MAHINDRA_H__
#include <iostream>
#include "AbsVehicleFactory.h"
#include "AbsCar.h"
#include "MahindraCar.h"
using namespace std;

class Mahindra : public AbsVehicleFactory
{
 public:
    Mahindra() { std::cout << "Mahindra()\n"; }
    ~Mahindra() { std::cout << "~Mahindra()\n"; }
    void getFactoryName();
    void createCar();
};
#endif      // __MAHINDRA_H__