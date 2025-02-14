#include <iostream>
#include <string>
#include "Vehicle.h"
#include "VehicleFactory.h"
using namespace std;

//Client
int main()
{
    string vType;
    std::cout << "Enter vehicle Type to be created : \n";
    std::cin >> vType;

    Vehicle *vehicle = VehicleFactory :: createVehicle(vType);
    if(vehicle) {
        vehicle->showVehicle();
        delete vehicle;
    }  
    
    return 0;
}