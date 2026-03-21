
// Pb1_Tema5.OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <algorithm>

Number::Number(const char* val, int b) : base(b) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
    digitsCount = strlen(value);
}

Number::Number(const Number& other) {
    base = other.base;
    digitsCount = other.digitsCount;
    value = new char[digitsCount + 1];
    strcpy(value, other.value);
}

long long Number::ToDecimal() const {
    return strtoll(value, nullptr, base);
}

char* Number::FromDecimal(long long val, int b) {
    char buffer[65];
    int i = 0;
    if (val == 0) return strdup("0");
    while (val > 0) {
        int rem = val % b;
        buffer[i++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'A');
        val /= b;
    }
    buffer[i] = '\0';
    std::reverse(buffer, buffer + i);
    char* res = new char[i + 1];
    strcpy(res, buffer);
    return res;
}

Number operator+(const Number& n1, const Number& n2) {
    int resultBase = std::max(n1.base, n2.base);
    long long sum = n1.ToDecimal() + n2.ToDecimal();
    char* tempStr = Number::FromDecimal(sum, resultBase);
    Number res(tempStr, resultBase);
    delete[] tempStr;
    return res;
}

Number operator-(const Number& n1, const Number& n2) {
    int resultBase = std::max(n1.base, n2.base);
    long long diff = n1.ToDecimal() - n2.ToDecimal();
    char* tempStr = Number::FromDecimal(diff, resultBase);
    Number res(tempStr, resultBase);
    delete[] tempStr;
    return res;
}

void Number::SwitchBase(int newBase) {
    if (base == newBase) return;
    long long dec = ToDecimal();
    delete[] value;
    value = FromDecimal(dec, newBase);
    base = newBase;
    digitsCount = strlen(value);
}

void Number::Print() const {
    std::cout << "Numar: " << value << " (Baza: " << base << ")" << std::endl;
}

int Number::GetDigitsCount() const { return digitsCount; }
int Number::GetBase() const { return base; }

char Number::operator[](int index) const {
    return value[index];
}

bool Number::operator>(const Number& other) const {
    return this->ToDecimal() > other.ToDecimal();
}

Number& Number::operator--() {
    char* temp = new char[digitsCount]; 
    strcpy(temp, value + 1);
    delete[] value;
    value = temp;
    digitsCount--;
    return *this;
}

Number Number::operator--(int) {
    Number copy(*this);
    value[digitsCount - 1] = '\0';
    digitsCount--;
    return copy;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
