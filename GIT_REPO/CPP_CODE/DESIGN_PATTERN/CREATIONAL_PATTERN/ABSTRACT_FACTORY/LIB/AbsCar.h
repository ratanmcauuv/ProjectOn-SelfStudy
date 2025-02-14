#ifndef __ABS_CAR_H__
#define __ABS_CAR_H__
#include <iostream>
using namespace std;

class AbsCar
{
 public:
    virtual ~AbsCar() = 0;
    virtual void getCarInfo() = 0;
};
#endif      // __ABS_CAR_H__