#include "ScalarConverter.hpp"

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

std::string	ScalarConverter::_appendDecimalIfNeeded(const std::string& str)
{
	if (
		str.find("nan") != std::string::npos ||
		str.find("inf") != std::string::npos ||
		str.find(".") != std::string::npos
	)
		return str;
	else
		return str + DBLE;
}


void	ScalarConverter::_convertChar(char c)
{
	const int	value = static_cast<int>(c);

	const std::string	charValue = std::string("'") + c + "'";
	const std::string	intValue = convertToString<int>(value);
	const std::string	floatValue = _appendDecimalIfNeeded(convertToString<float>(static_cast<float>(value))) + FLTE;
	const std::string	doubleValue = _appendDecimalIfNeeded(convertToString<double>(static_cast<double>(value)));
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertInt(int num)
{
	const std::string	charValue = _getCharValue(num);
	const std::string	intValue = convertToString<int>(num);
	const std::string	floatValue = _appendDecimalIfNeeded(convertToString<float>(static_cast<float>(num))) + FLTE;
	const std::string	doubleValue = _appendDecimalIfNeeded(convertToString<double>(static_cast<double>(num)));
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertFloat(float num)
{
	const int	intNum = static_cast<int>(num);

	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<float>(num);
	const std::string	floatValue = _appendDecimalIfNeeded(convertToString<float>(num)) + FLTE;
	const std::string	doubleValue = _appendDecimalIfNeeded(convertToString<double>(static_cast<double>(num)));
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertDouble(double num)
{
	const int	intNum = static_cast<int>(num);

	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<double>(num);
	const std::string	floatValue = _appendDecimalIfNeeded(convertToString<float>(static_cast<float>(num))) + FLTE;
	const std::string	doubleValue = _appendDecimalIfNeeded(convertToString<double>(num));
	_print(charValue, intValue, floatValue, doubleValue);
}

std::string	ScalarConverter::_getCharValue(int num)
{
	std::string	charValue;

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