#include "MovieSeries.h"
#include <cstdio>

void MovieSeries::init() 
{
    count = 0;
}

void MovieSeries::add(Movie* m) 
{
    if (count < 16) {
        movies[count++] = m;
    }
}

void MovieSeries::sort() 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++)
        {
            if (movies[i]->get_passed_years() < movies[j]->get_passed_years()) 
            {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void MovieSeries::print() const 
{
    for (int i = 0; i < count; i++) 
    {
        printf("%s | Year: %d | Score: %.1f | Length: %d | Passed years: %d\n",
            movies[i]->get_name(),
            movies[i]->get_year(),
            movies[i]->get_score(),
            movies[i]->get_length(),
            movies[i]->get_passed_years());
    }
}