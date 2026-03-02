#pragma once

#include <string>

class Student 
{
private:
    std::string name;
    float math;
    float english;
    float history;

public:
    void setName(std::string n);
    void setMath(float m);
    void setEnglish(float e);
    void setHistory(float h);

    std::string getName();
    float getMath();
    float getEnglish();
    float getHistory();

    float getAverage();
};