#ifndef __ABS_VEHICLE_FACTORY_H__
#define __ABS_VEHICLE_FACTORY_H__
#include <iostream>
using namespace std;

class AbsVehicleFactory
{
 public:
    virtual ~AbsVehicleFactory() = 0;
    virtual void getFactoryName() = 0;
    virtual void createCar() = 0;
};
#endif      // __ABS_VEHICLE_FACTORY_H__