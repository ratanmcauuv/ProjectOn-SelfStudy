#ifndef __TATA_CAR_H__
#define __TATA_CAR_H__
#include <iostream>
#include "AbsCar.h"
using namespace std;

class TataCar : public AbsCar
{
 public:
    void getCarInfo();
    ~TataCar();
};
#endif      // __TATA_CAR_H__