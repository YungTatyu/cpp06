#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#define ASCII_NUM 127
#define CHAREQ "char: "
#define INTEQ  "int: "
#define FLTEQ "float: "
#define DBLEQ "double: "

#define IMPOSSIBLE "impossible"
#define NOPRINT "Non displayable"

#define PNAN "+nan"
#define NNAN "-nan"


class ScalarConverter
{
private:
	enum type {
		TP_CHAR,
		TP_INT,
		TP_FLOAT,
		TP_DOUBLE,
		TP_STR,
	};
	ScalarConverter();
	static enum type _getStringType(const std::string& str);
	static void	_convertChar(char c);
	static void	_convertInt(int num);
	static void	_convertFloat(float num);
	static void	_convertDouble(double num);
	static bool	_isConvertibleToAscii(const std::string& str);
	// static bool	_isFloatInfOrNan(const std::string& str);
	// static float	_getFloatInfOrNan(const std::string& str);
	static std::string	_popbackF(const std::string& str);

	template <typename T>
	static bool	_isConvertible(const std::string& str)
	{
		std::istringstream iss(str);
		T	value; //指定された型に変換する
		char	remaining; //余り
		const bool	isSuccess = static_cast<bool>(iss >> value);
		const bool	hasRemaining = static_cast<bool>(iss >> remaining);

		if (str == PNAN || str == NNAN)
			return false;
		return isSuccess && !hasRemaining;
	};
	static void	_print(const std::string& charValue, const std::string& intValue,
			const std::string& floatValue, const std::string& doubleValue);
	static std::string	_getCharValue(int num);

	template <typename T>
	static std::string	_getIntValue(T num)
	{
		const T	max = static_cast<T>(std::numeric_limits<int>::max());
		const T	min = static_cast<T>(std::numeric_limits<int>::min());
		if (std::isnan(num) || num > max || num < min)
			return IMPOSSIBLE;

		std::stringstream ss;
		ss << static_cast<int>(num);
		return ss.str();
	}

	template <typename T1, typename T2>
	static std::string	_getFloatValue(T1 num)
	{
		const T1	max = static_cast<T1>(std::numeric_limits<T2>::max());
		const T1	min = static_cast<T1>(std::numeric_limits<T2>::min());
		if ((!std::isinf(max) && !std::isinf(min) && !std::isinf(num)) && (num > max || num < min))
			return IMPOSSIBLE;

		std::stringstream ss;
		ss << static_cast<T2>(num);
		return ss.str();
	}
public:
	static void	convert(std::string str);

	template <typename T>
	static std::string	convertToString(T value)
	{
		std::stringstream	ss;
		ss << value;

		return ss.str();
	}

	template <typename T>
	static T	stringToType(const std::string& str)
	{
		std::istringstream iss(str);
		T	value;

		iss >> value;
		return value;
	}
};

#endif