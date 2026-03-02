#include "StudentsFunctions.h"

int compareName(Student s1, Student s2) 
{
    if (s1.getName() == s2.getName())
        return 0;
    if (s1.getName() > s2.getName())
        return 1;
    return -1;
}

int compareMath(Student s1, Student s2)
{
    if (s1.getMath() == s2.getMath())
        return 0;
    if (s1.getMath() > s2.getMath())
        return 1;
    return -1;
}

int compareEnglish(Student s1, Student s2) 
{
    if (s1.getEnglish() == s2.getEnglish())
        return 0;
    if (s1.getEnglish() > s2.getEnglish())
        return 1;
    return -1;
}

int compareHistory(Student s1, Student s2)
{
    if (s1.getHistory() == s2.getHistory())
        return 0;
    if (s1.getHistory() > s2.getHistory())
        return 1;
    return -1;
}

int compareAverage(Student s1, Student s2)
{
    if (s1.getAverage() == s2.getAverage())
        return 0;
    if (s1.getAverage() > s2.getAverage())
        return 1;
    return -1;
}