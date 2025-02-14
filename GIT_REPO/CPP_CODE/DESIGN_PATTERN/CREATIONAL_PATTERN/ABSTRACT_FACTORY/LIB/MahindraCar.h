#ifndef __MAHINDRA_CAR_H__
#define __MAHINDRA_CAR_H__
#include <iostream>
#include "AbsCar.h"
using namespace std;

class MahindraCar : public AbsCar
{
 public:
    void getCarInfo();
    ~MahindraCar();
};
#endif      // __MAHINDRA_CAR_H__