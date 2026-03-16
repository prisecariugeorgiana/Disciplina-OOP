#pragma once
#include <vector>
#include <string>

class Sort
{
private:
    std::vector<int> v;

public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(std::vector<int> vec, int count);
    Sort(int count, ...);
    Sort(std::string numbers);

    void BubbleSort();
    void InsertSort();
    void QuickSort(int left, int right);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};