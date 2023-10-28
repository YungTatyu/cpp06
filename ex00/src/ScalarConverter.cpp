#include "ScalarConverter.hpp"

// #define INFF "inff"
// #define PINFF "+inff"
// #define NINFF "-inff"
// #define NANF "nanf"

#define DBLE ".0"
#define FLTE "f"

void	ScalarConverter::convert(std::string str)
{
	const enum type	type = ScalarConverter::_getStringType(str);

	switch (type)
	{
	case TP_CHAR:
		_convertChar(stringToType<char>(str));
		break;
	case TP_INT:
		_convertInt(stringToType<int>(str));
		break;
	case TP_FLOAT:
		_convertFloat(stringToType<float>(_popbackF(str)));
		break;
	case TP_DOUBLE:
		_convertDouble(stringToType<double>(str));
		break;
	default:
		_print(IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE, IMPOSSIBLE);
		break;
	}
}

enum ScalarConverter::type	ScalarConverter::_getStringType(const std::string& str)
{
	if (_isConvertibleToAscii(str))
		return TP_CHAR;
	else if (_isConvertible<int>(str))
		return TP_INT;
	else if (_isConvertible<double>(str))
		return TP_DOUBLE;
	else if (_isConvertible<float>(_popbackF(str)))
		return TP_FLOAT;
	else
		return TP_STR;
}

// float	ScalarConverter::_getFloatInfOrNan(const std::string& str)
// {
// 	float	value = 0.0f;

// 	if (str == INFF)
// 		value = std::numeric_limits<float>::infinity();
// 	else if (str == PINFF)
// 		value = +std::numeric_limits<float>::infinity();
// 	else if (str == NINFF)
// 		value = -std::numeric_limits<float>::infinity();
// 	else if (str == NANF)
// 		value = std::numeric_limits<float>::quiet_NaN();
// 	return value;
// }


// bool	ScalarConverter::_isFloatInfOrNan(const std::string& str)
// {
// 	return str == INFF || str == PINFF || str == NINFF || str == NANF;
// }

std::string	ScalarConverter::_popbackF(const std::string& str)
{
	std::string	copy = str;

	if (!copy.empty() && *(copy.end() - 1) == 'f')
		copy.erase(copy.end() - 1);
	return copy;
}

/**
 * @brief printableなASCIIの場合はtrueを返す
 *
 * @param str
 * @return true
 * @return false
 */
bool	ScalarConverter::_isConvertibleToAscii(const std::string& str)
{
	return str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]);
}

void	ScalarConverter::_convertChar(char c)
{
	const int	value = static_cast<int>(c);

	const std::string	charValue = std::string("'") + c + "'";
	const std::string	intValue = convertToString<int>(value);
	const std::string	floatValue = convertToString<float>(static_cast<float>(value)) + DBLE + FLTE;
	const std::string	doubleValue = convertToString<double>(static_cast<double>(value)) + DBLE;
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertInt(int num)
{
	std::cout << "_convertInt called\n";
	const std::string	charValue = _getCharValue(num);
	const std::string	intValue = convertToString<int>(num);
	const std::string	floatValue = convertToString<float>(static_cast<float>(num)) + DBLE + FLTE;
	const std::string	doubleValue = convertToString<double>(static_cast<double>(num)) + DBLE;
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertFloat(float num)
{
	const int	intNum = static_cast<int>(num);

	std::cout << "_convertFloat called\n";
	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<float>(num);
	const std::string	floatValue = convertToString<float>(num) + FLTE;
	const std::string	doubleValue = _getFloatValue<double, float>(num);
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertDouble(double num)
{
	const int	intNum = static_cast<int>(num);

	std::cout << "_convertDouble called\n";
	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<double>(num);
	const std::string	floatValue = _getFloatValue<float, double>(num) + FLTE;
	const std::string	doubleValue = convertToString<double>(num);
	_print(charValue, intValue, floatValue, doubleValue);
}

std::string	ScalarConverter::_getCharValue(int num)
{
	std::string	charValue;

	std::cout << num << '\n';
	if (num > ASCII_NUM || num < 0)
		return IMPOSSIBLE;
	else
		return std::isprint(num) ? std::string(1, static_cast<char>(num)) : NOPRINT;
}


void	ScalarConverter::_print(
			const std::string& charValue,
			const std::string& intValue,
			const std::string& floatValue,
			const std::string& doubleValue)
{
	std::cout << std::string(CHAREQ) + charValue + '\n'
		<< std::string(INTEQ) + intValue + '\n'
		<< std::string(FLTEQ) + floatValue + '\n'
		<< std::string(DBLEQ) + doubleValue + '\n';
}