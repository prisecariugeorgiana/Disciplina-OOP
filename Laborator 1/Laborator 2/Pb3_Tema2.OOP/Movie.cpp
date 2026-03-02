#include "Movie.h"
#include <cstring>
#include <ctime>

Movie::Movie() 
{
    name[0] = '\0';
    year = 0;
    score = 0;
    length = 0;
}

void Movie::set_name(const char* n)
{
    strncpy(name, n, 255);
    name[255] = '\0';
}

const char* Movie::get_name() const 
{
    return name;
}

void Movie::set_year(int y) 
{
    year = y;
}

int Movie::get_year() const
{
    return year;
}

void Movie::set_score(double s) 
{
    if (s >= 1 && s <= 10)
        score = s;
}

double Movie::get_score() const 
{
    return score;
}

void Movie::set_length(int l) 
{
    length = l;
}

int Movie::get_length() const 
{
    return length;
}

int Movie::get_passed_years() const 
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return (now->tm_year + 1900) - year;
}