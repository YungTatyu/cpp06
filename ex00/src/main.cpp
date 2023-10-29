#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>
#include <cmath>
#include <sstream>
#include <iostream>

// template <typename T1, typename T2>
// std::string	_getFloatValue(T1 num)
// {
// 	const T1	max = static_cast<T1>(std::numeric_limits<T2>::max());
// 	const T1	min = static_cast<T1>(std::numeric_limits<T2>::min());
// 	if ((!std::isinf(max) && !std::isinf(min)) && (num > max || num < min))
// 		return NULL;

// 	std::stringstream ss;
// 	ss << static_cast<T2>(num);
// 	return ss.str();
// }

int	main(int argc, char *argv[])
{
	while (argc != 1)
	{
		std::cout << "converting " << argv[--argc] << "...\n";
		ScalarConverter::convert(argv[argc]);
		std::cout << "\n";
	}

	std::cout <<  static_cast<float>(FLT_MIN) << "\n";
	// std::cout << _getFloatValue<float, double>(1.1f) << "\n";
	// std::cout << INT_MAX << "\n";
	// std::cout << 2147483647.0f << "\n";
	// std::cout << static_cast<float>(INT_MAX) << "\n";
	// std::cout << static_cast<double>(INT_MAX) << "\n";
	// int num = static_cast<float>(8388609);
	// int num = static_cast<float>(1 << 31);
	// num = static_cast<double>(INT_MAX);
	// int num = static_cast<float>(INT_MAX);
	// std::cout << num << "\n";
	// int num = static_cast<float>(1 << 23);

	// std::cout << std::numeric_limits<float>::max() + 10.0f << "\n";
	// num = static_cast<float>(1 << 24);
	// std::cout << num << "\n";
	// double	n = NAN;
	// std::cout << n << '\n';
	// float pos_inf = std::numeric_limits<float>::infinity();  // 正の無限大
	// float neg_inf = -std::numeric_limits<float>::infinity(); // 負の無限大

	// std::cout << "Positive Infinity: " << pos_inf << std::endl;
	// std::cout << "Negative Infinity: " << neg_inf << std::endl;


	// n = NAN;
	// const float	fNum = static_cast<float>(n);
	// std::cout << fNum << "\n";

	// float	f = FLT_MIN;
	// std::cout << f << '\n' << FLT_MIN << '\n';
	// std::stringstream ss;

	// ss << f;
	// std::cout << "str=" << ss.str() << '\n';
	// std::cout << 42.1f << '\n';


	// ss.str("");
	// ss << 'a';
	// std::cout << ss.str() << '\n';

	// INT_MIN;
	// std::istringstream iss("ABC");
	// char value;
	// char	remaining;
	// bool	b = iss >> value;
	// bool hasRmeining = iss >> remaining;
	// // bool	b = iss.operator>>(value);
	// std::cout << "b=" << b << "\n";
	// std::cout << "value="  << value << "\n";
	// std::cout  << "isFail=" << iss.fail() << "\n";
	// std::cout  << "remaining=" << remaining << "\n";
	// std::cout  << "hasremaining=" << hasRmeining << "\n";

	// std::cout << "floatmax=" << FLT_MAX << '\n';
	// std::cout << "doublemax=" << DBL_MAX << '\n';
	// std::cout << "float cast doublemax=" << static_cast<float>(DBL_MAX) << '\n';

	// num = static_cast<float>(INT_MIN + 1);
// 	int bit = 24;
// 	num = static_cast<float>(-(1 << bit) + 1);
// 	std::cout << num << "\n";
// 	num = static_cast<float>(-(1 << bit));
// 	std::cout << num << "\n";

// 	// long	l_bit = 51;
// 	// long	n = static_cast<double>(1 << l_bit);
// 	long	n = static_cast<double>(pow(2.0, 63.0) - 1.0);
// 	// n = static_cast<double>(LONG_MAX);
// 	// n = static_cast<double>();
// 	std::cout << n << "\n";
}