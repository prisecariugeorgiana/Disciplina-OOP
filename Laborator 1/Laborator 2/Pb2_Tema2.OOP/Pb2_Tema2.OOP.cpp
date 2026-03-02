#include <iostream>
#include "Student.h"
#include "StudentsFunctions.h"

using namespace std;

int main() 
{
    Student s1, s2;

    s1.setName("Ana");
    s1.setMath(9);
    s1.setEnglish(8);
    s1.setHistory(10);

    s2.setName("Maria");
    s2.setMath(7);
    s2.setEnglish(9);
    s2.setHistory(8);

    cout << "Media Ana: " << s1.getAverage() << endl;
    cout << "Media Maria: " << s2.getAverage() << endl;

    cout << "Comparare medie: " << compareAverage(s1, s2) << endl;

    return 0;
}