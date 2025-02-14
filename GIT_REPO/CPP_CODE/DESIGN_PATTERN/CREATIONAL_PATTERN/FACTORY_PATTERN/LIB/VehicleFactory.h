#ifndef __VEHICLE_FACTORY_H__
#define __VEHICLE_FACTORY_H__
#include <string>
#include "Vehicle.h"
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Bus.h"
#include "Tempo.h"
using namespace std;

class VehicleFactory
{
 public:
    static Vehicle *createVehicle(std::string &vType);
};
#endif      // __VEHICLE_FACTORY_H__