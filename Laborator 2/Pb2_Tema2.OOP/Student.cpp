#include "Student.h"

void Student::setName(std::string n)
{
    name = n;
}

void Student::setMath(float m) 
{
    if (m >= 1 && m <= 10)
        math = m;
}

void Student::setEnglish(float e) 
{
    if (e >= 1 && e <= 10)
        english = e;
}

void Student::setHistory(float h) 
{
    if (h >= 1 && h <= 10)
        history = h;
}

std::string Student::getName() 
{
    return name;
}

float Student::getMath() 
{
    return math;
}

float Student::getEnglish()
{
    return english;
}

float Student::getHistory() 
{
    return history;
}

float Student::getAverage() 
{
    return (math + english + history) / 3;
}