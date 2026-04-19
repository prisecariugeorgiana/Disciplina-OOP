#include <iostream>

constexpr float operator "" _Kelvin(long double k) 
{
    return static_cast<float>(k - 273.15);
}

constexpr float operator "" _Fahrenheit(long double f)
{
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}

constexpr float operator "" _Kelvin(unsigned long long k)
{
    return static_cast<float>(static_cast<long double>(k) - 273.15);
}
 
constexpr float operator "" _Fahrenheit(unsigned long long f)
{
    return static_cast<float>((static_cast<long double>(f) - 32) * 5.0 / 9.0);
}

int main() 
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << " C" << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << " C" << std::endl;

    return 0;
}