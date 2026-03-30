#pragma once
#include "Car.h"

class Hyundai : public Car
{
public:
    Hyundai()
    {
        name = "Hyundai";
        fuelCapacity = 53;      // litri
        fuelConsumption = 8;    // litri la 100km
        avgSpeedRain = 80;      // km/h
        avgSpeedSunny = 130;
        avgSpeedSnow = 60;
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