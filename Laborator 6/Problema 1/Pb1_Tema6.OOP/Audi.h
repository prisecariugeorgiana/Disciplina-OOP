#pragma once
#include "Car.h"

class Audi : public Car 
{
public:
    Audi()
    {
        name = "Audi";
        fuelCapacity = 60;      // litri
        fuelConsumption = 7;    // litri la 100km
        avgSpeedRain = 70;      // km/h
        avgSpeedSunny = 110;
        avgSpeedSnow = 50;
    }

    double GetSpeed(Weather w) override 
    {
        if (w == Weather::Rain) return avgSpeedRain;
        if (w == Weather::Snow) return avgSpeedSnow;
        return avgSpeedSunny;
    }

    std::string GetName() override
    { 
        return name;
    }
};