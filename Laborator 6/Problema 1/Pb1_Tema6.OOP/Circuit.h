#pragma once
#include "Car.h"
#include <vector>

struct Result 
{
    std::string name;
    double time;
    bool finished;
};

class Circuit 
{
    double length;
    Weather weather;
    std::vector<Car*> cars;
    std::vector<Result> results;

public:
    void SetLength(double l);
    void SetWeather(Weather w);
    void AddCar(Car* c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};