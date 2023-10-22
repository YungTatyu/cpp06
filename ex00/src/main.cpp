#include "ScalarConverter.hpp"
#include <climits>
#include <math.h>

int	main()
{
	// std::cout << INT_MAX << "\n";
	// std::cout << 2147483647.0f << "\n";
	// std::cout << static_cast<float>(INT_MAX) << "\n";
	// std::cout << static_cast<double>(INT_MAX) << "\n";
	// int num = static_cast<float>(8388609);
	// int num = static_cast<float>(1 << 31);
	// num = static_cast<double>(INT_MAX);
	int num = static_cast<float>(INT_MAX);
	std::cout << num << "\n";
	// num = static_cast<float>(INT_MIN + 1);
	int bit = 24;
	num = static_cast<float>(-(1 << bit) + 1);
	std::cout << num << "\n";
	num = static_cast<float>(-(1 << bit));
	std::cout << num << "\n";

	// long	l_bit = 51;
	// long	n = static_cast<double>(1 << l_bit);
	long	n = static_cast<double>(pow(2.0, 63.0) - 1.0);
	// n = static_cast<double>(LONG_MAX);
	// n = static_cast<double>();
	std::cout << n << "\n";
}