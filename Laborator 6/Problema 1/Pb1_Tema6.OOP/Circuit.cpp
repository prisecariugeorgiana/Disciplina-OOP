#include "Circuit.h"
#include <iostream>
#include <algorithm> 

void Circuit::SetLength(double l) 
{
    length = l;
}
void Circuit::SetWeather(Weather w) 
{
    weather = w;
}
void Circuit::AddCar(Car* c)
{
    cars.push_back(c);
}

void Circuit::Race() 
{
    for (Car* c : cars) 
    {
        double speed = c->GetSpeed(weather);
        double fuelNeeded = (length / 100.0) * c->fuelConsumption;

        Result r;
        r.name = c->GetName();

        if (fuelNeeded <= c->fuelCapacity) 
        {
            r.time = length / speed; 
            r.finished = true;
        }
        else 
        {
            r.time = -1; 
            r.finished = false;
        }
        results.push_back(r);
    }

    std::sort(results.begin(), results.end(), [](const Result& a, const Result& b)
        {
        if (a.finished && b.finished) return a.time < b.time;
        return a.finished > b.finished; 
        });
}

void Circuit::ShowFinalRanks()
{
    std::cout << "Clasament Final \n";
    int rank = 1;
    for (auto& r : results) 
    {
        if (r.finished) 
        {
            std::cout << rank++ << ". " << r.name << " a terminat in " << r.time << " ore.\n";
        }
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    std::cout << "Masini care au ramas fara benzina \n";
    for (auto& r : results) 
    {
        if (!r.finished) 
        {
            std::cout << "- " << r.name << "\n";
        }
    }
}