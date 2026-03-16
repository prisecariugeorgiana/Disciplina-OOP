#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Sort s1(5, 1, 50);
    cout << "Lista random:\n";
    s1.Print();
    s1.BubbleSort();
    cout << "BubbleSort:\n";
    s1.Print();
    Sort s2{ 8,3,6,2,9 };
    cout << "\nLista initiala:\n";
    s2.Print();
    s2.InsertSort();
    cout << "InsertSort:\n";
    s2.Print();
    Sort s3("10,40,5,20,15");
    cout << "\nDin string:\n";
    s3.Print();
    s3.QuickSort(0, s3.GetElementsCount() - 1);
    cout << "QuickSort:\n";
    s3.Print();

    cout << "\n Numar elemente: " << s3.GetElementsCount() << endl;
    cout << "Element index 2: " << s3.GetElementFromIndex(2) << endl;

    return 0;
}