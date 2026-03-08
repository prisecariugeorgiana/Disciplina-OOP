#include "math.h"
#include <string.h>
#include <stdarg.h>

int math::Add(int a, int b)
{
	return a + b;
}
int math::Add(int a, int b, int c)
{
	return a + b + c;
}
int math::Add(double a, double b) 
{
	return int(a + b);
}
int math::Add(double a, double b, double c)
{
	return int(a + b + c);
}
int math::Mul(int a, int b)
{
	return a * b;
}		
int math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int math::Mul(double a, double b)
{
	return int(a * b);
}
int math::Mul(double a, double b, double c)
{
	return int(a * b * c);
}
int math::Add(int count, ...)
{
	va_list vl;
	va_start(vl, count);
	int suma = 0;
	for (int i = 0; i < count;i++)
	{
		suma = suma + va_arg(vl, int);
	}
	va_end(vl);
	return suma;
}
char* Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
	{
		return nullptr;
	}
	char* result = new char[strlen(s1) + strlen(s2)];
	if (result ==  nullptr)
	{
		return nullptr;
	} 
	if (result != nullptr) 
	{
		strcpy(result, s1);
		strcat(result, s2);
	}
		return result;
}