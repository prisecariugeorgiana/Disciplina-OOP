#include <iostream>
#include <string.h>
#include "math.h"

int main()
{
	std::cout << math::Add(1, 2) << std::endl;
	std::cout << math::Add(1, 2, 3) << std::endl;

	const char* s1 = "Laborator";
	const char* s2 = "OOP";
	char* result = math::Add(s1, s2);
	if (result != nullptr)
	{
		std::cout << result << std::endl;
	}
	return 0;
}

