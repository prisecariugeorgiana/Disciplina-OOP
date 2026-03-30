#pragma once

#include "Weather.h"
#include <string>

class Car 
{
public:
   
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;
    std::string name;

    virtual ~Car() {}

    virtual double GetSpeed(Weather w) = 0;
    virtual std::string GetName() = 0;
};