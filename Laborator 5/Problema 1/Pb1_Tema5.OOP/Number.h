#pragma once

class Number 
{
    char* value; 
    int base;   
    int digitsCount;

public:
    Number(const char* value, int base);
    Number(int value); 
    ~Number();

    Number(const Number& other);
    Number(Number&& other) noexcept;
    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(const char* val);

    char operator[](int index) const;
    bool operator>(const Number& other) const;

    Number& operator--();    
    Number operator--(int); 

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    long long ToDecimal() const;
    static char* FromDecimal(long long val, int base); 
};
