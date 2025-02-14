#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <iostream>

class Vehicle
{
 public:
    virtual void showVehicle() = 0;
    virtual ~Vehicle() = 0;
};

#endif      // __VEHICLE_H__