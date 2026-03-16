#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>

using namespace std;

Sort::Sort(int count, int min, int max)
{
    srand(time(0));

    for (int i = 0; i < count; i++)
        v.push_back(min + rand() % (max - min + 1));
}

Sort::Sort(initializer_list<int> list)
{
    for (int x : list)
        v.push_back(x);
}

Sort::Sort(vector<int> vec, int count)
{
    for (int i = 0; i < count && i < vec.size(); i++)
        v.push_back(vec[i]);
}

Sort::Sort(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        v.push_back(va_arg(args, int));

    va_end(args);
}

Sort::Sort(string numbers)
{
    stringstream ss(numbers);
    string temp;

    while (getline(ss, temp, ','))
        v.push_back(stoi(temp));
}

void Sort::BubbleSort()
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void Sort::InsertSort()
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

void Sort::QuickSort(int left, int right)
{
    int i = left;
    int j = right;
    int pivot = v[(left + right) / 2];

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;

        while (v[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j)
        QuickSort(left, j);

    if (i < right)
        QuickSort(i, right);
}

void Sort::Print()
{
    for (int x : v)
        cout << x << " ";

    cout << endl;
}

int Sort::GetElementsCount()
{
    return v.size();
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < v.size())
        return v[index];

    return -1;
}