#ifndef __TATAMOTORS_H__
#define __TATAMOTORS_H__
#include <iostream>
#include "AbsVehicleFactory.h"
#include "TataCar.h"
#include "AbsCar.h"
using namespace std;

class TataMotors : public AbsVehicleFactory
{
 public:
    TataMotors() { std::cout << "TataMotors()\n"; }
    ~TataMotors() { std::cout << "~TataMotors()\n"; }
    void getFactoryName();
    void createCar();
};
#endif      // __TATAMOTORS_H__