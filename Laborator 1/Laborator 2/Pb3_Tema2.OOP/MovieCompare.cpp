#include "MovieCompare.h"
#include <cstring>

int movie_compare_name(const Movie& m1, const Movie& m2)
{
    int r = strcmp(m1.get_name(), m2.get_name());
    if (r < 0) return -1;
    if (r > 0) return 1;
    return 0;
}

int movie_compare_year(const Movie& m1, const Movie& m2)
{
    if (m1.get_year() < m2.get_year()) return -1;
    if (m1.get_year() > m2.get_year()) return 1;
    return 0;
}

int movie_compare_score(const Movie& m1, const Movie& m2) 
{
    if (m1.get_score() < m2.get_score()) return -1;
    if (m1.get_score() > m2.get_score()) return 1;
    return 0;
}

int movie_compare_length(const Movie& m1, const Movie& m2) 
{
    if (m1.get_length() < m2.get_length()) return -1;
    if (m1.get_length() > m2.get_length()) return 1;
    return 0;
}

int movie_compare_passed_years(const Movie& m1, const Movie& m2) 
{
    if (m1.get_passed_years() < m2.get_passed_years()) return -1;
    if (m1.get_passed_years() > m2.get_passed_years()) return 1;
    return 0;
}