#include "AutoMobileFactory.h"
#include <algorithm>

AbsVehicleFactory *AutoMobileFactory::GetVehicleFactory(std::string &autoMobCompany)
{
    AbsVehicleFactory *amf;
    std::transform(autoMobCompany.begin(), autoMobCompany.end(), autoMobCompany.begin(), ::tolower);

    if(autoMobCompany == "tata") {
        amf = new TataMotors();
    } else if(autoMobCompany == "mahindra") {
        amf = new Mahindra();
    }
    return amf;
}