#ifndef __AUTOMOBILE_FACTORY_H__
#define __AUTOMOBILE_FACTORY_H__
#include <string>
#include "AbsVehicleFactory.h"
#include "TataMotors.h"
#include "Mahindra.h"
using namespace std;

class AutoMobileFactory
{
 public:
    static AbsVehicleFactory *GetVehicleFactory(std::string &vType);
};
#endif      // __AUTOMOBILE_FACTORY_H__