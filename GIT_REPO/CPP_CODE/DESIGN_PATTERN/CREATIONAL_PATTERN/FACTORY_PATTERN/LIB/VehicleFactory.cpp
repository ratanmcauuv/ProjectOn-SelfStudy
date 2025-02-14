#include "VehicleFactory.h"
#include <algorithm>

Vehicle *VehicleFactory::createVehicle(std::string &vType)
{
    Vehicle *vehicle = nullptr;
    std::transform(vType.begin(), vType.end(), vType.begin(), ::tolower);

    if(vType == "car") {
        vehicle = new Car();
    } else if(vType == "bike") {
        vehicle = new Bike();
    } else if(vType == "bus") {
        vehicle = new Bus();
    } else if(vType == "tempo") {
        vehicle = new Tempo();
    }

    return vehicle;
}