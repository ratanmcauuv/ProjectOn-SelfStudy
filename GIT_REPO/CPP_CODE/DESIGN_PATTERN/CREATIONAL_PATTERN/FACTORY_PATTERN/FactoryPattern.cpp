#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Library
class Vehicle
{
 public:
    virtual void showVehicle() = 0;
};

class Car : public Vehicle
{
 public:
    void showVehicle() {
        std::cout << "Creating Car\n";
    }
};

class Bike : public Vehicle
{
 public:
    void showVehicle() {
        std::cout << "Creating Bike\n"; 
    }
};

//Client
int main()
{
    string vType;
    std::vector<string> VehicleCollection = { "CAR", "BIKE" };
    std::cout << "Enter vehicle Type to be created : \n";
    std::cin >> vType;
    auto found = std::find_if(VehicleCollection.begin(), VehicleCollection.end(), [&](auto v){
        return vType == v;
    });
    if(found == VehicleCollection.end()) {
        std::cout << "Incorrect Vehicle Type !!\n";
        return 0;
    }

    Vehicle *vehicle;
    if(vType == "CAR") {
        vehicle = new Car();
    } else if(vType == "BIKE") {
        vehicle = new Bike();
    }

    vehicle->showVehicle();
    
    return 0;
}