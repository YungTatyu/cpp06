#include "ScalarConverter.hpp"
#include <sstream>

#define CHAREQ "char: ";
#define INTEQ  "int: ";
#define FLTEQ "float: ";
#define DBLEEQ "double: ";

#define IMPOSSIBLE "impossible";
#define NOPRINT "Non displayable";

void	ScalarConverter::convert(const std::string& str)
{
	enum type	type = _getStringType(str);

	switch (type)
	{
	case TP_CHAR:
		_convertChar(stringToType<char>(str));
		break;
	case TP_INT:
		_convertINT(stringToType<int>(str));
		break;
	case TP_FLOAT:
		_convertFloat(stringToType<float>(str));
		break;
	case TP_DOUBLE:
		_convertDouble(stringToType<double>(str));
		break;
	default:
		_print();
		break;
	}
}

enum type	ScalarConverter::_getStringType(const std::string& str) const
{
	if (_isConvertibleToAscii(str))
		return TP_CHAR;
	else if (_isConvertible<int>(str))
		return TP_INT;
	else if (_isConvertible<flaot>(str))
		return TP_FLOAT;
	else if (_isConvertible<double>(str))
		return TP_DOUBLE;
	else
		return TP_STR;
}

/**
 * @brief printableなASCIIの場合はtrueを返す
 *
 * @param str
 * @return true
 * @return false
 */
bool	ScalarConverter::_isConvertibleToAscii(const std::string& str) const
{
	return str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]);
}
/**
 * @brief 文字列をint, float, doubleに変換し、成功すればtrue、失敗すればfalseを返す
 *
 * 余りがある場合はfalseを返す
 *
 * @tparam T
 * @param str
 * @return true
 * @return false
 */
template<typename T>
bool	ScalarConverte<T>::_isConvertible(const std::string& str) const
{
	std::istringstream iss(str);
	T	value; //指定された型に変換する
	char	remaining; //余り
	const bool	isSuccess = iss >> value;
	const bool	hasRemaining = iss >> remainig;

	return isSuccess && !hasRemaining;
}

void	ScalarConverter::_convertChar(char& c) const
{
	const int	value = static_cast<int>(c);
	const std::stringstream	ss;
	ss << value;

	const std::string	charValue = std::string("'") + c + "'";
	const std::string	intValue = ss.str();
	const std::string	floatValue = ss.str() + ".0f";
	const std::string	doubleValue = ss.str() + ".0";
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertInt(int& num) const
{
	const std::stringstream	ss;
	ss << num;

	const std::string	charValue = _getCharValue(num);
	const std::string	intValue = ss.str();
	const std::string	floatValue = ss.str() + ".0f";
	const std::string	doubleValue = ss.str() + ".0";
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertFloat(float& num) const
{
	const int	intNum = static_cast<int>(num);
	const std::stringstream	ss;
	ss << num;

	std::string	charValue;
	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<float>(num);
	const std::string	floatValue = ss.str() + "f";
	const std::string	doubleValue = _getFloatValue<double, float>(num);
	_print(charValue, intValue, floatValue, doubleValue);
}

void	ScalarConverter::_convertDouble(double& num) const
{
	const int	intNum = static_cast<int>(num);
	const std::stringstream	ss;
	ss << num;

	const std::string	charValue = _getCharValue(intNum);
	const std::string	intValue = _getIntValue<float>(num);
	const std::string	floatValue = ss.str() + "f";
	const std::string	doubleValue = _getFloatValue<double, float>(num);
	_print(charValue, intValue, floatValue, doubleValue);
}

std::stirng	ScalarConverter::_getCharValue(int& num)
{
	std::string	charValue;

	if (num <= ASCII_NUM && num >= 0)
		return IMPOSSIBLE;
	else
		return std::isprint(num) ? static_cast<char>(num) : NOPRINT;
}


std::stirng	ScalarConverter::_getIntValue(T num)
{
	const T	max = static_cast<T>(std::numeric_limits<int>::max());
	const T	min = static_cast<T>(std::numeric_limits<int>::min());
	if (num > max || num < min)
		return IMPOSSIBLE;

	std::stringstream ss;
	ss << static_cast<int>(num);
	return ss.str();
}

T	ScalarConverter::stringToType(const std::string& str)
	{
		std::istringstream iss(str);
		T	value;

		iss >> value;
		return value;
	}

/**
 * @brief T1型をT2型に変更した結果の文字列を作成する
 *
 * T2型のoverflowをチェック
 *
 * @tparam T1
 * @tparam T2
 * @param num
 * @return std::stirng
 */
template<typename T1, typename T2>
static std::stirng	ScalarConverter::_getFloatValue(T1 num)
{
	const T1	max = static_cast<T1>(std::numeric_limits<T2>::max());
	const T1	min = static_cast<T1>(std::numeric_limits<T2>::min());
	if ((!std::isinf(max) && !std::isinf(min)) && (num > max || num < min))
		return IMPOSSIBLE;

	std::stringstream ss;
	ss << static_cast<T2>(num);
	return ss.str();
}

void	ScalarConverter::_print(
			const std::string& charValue,
			const std::string& intValue,
			const std::string& floatValue,
			const std::string& doubleValue)
{
	std::cout << std::string(CHAREQ) + charValue + '\n'
		<< std::string(INTREQ) + intValue + '\n'
		<< std::string(FLOATREQ) + floatValue + '\n'
		<< std::string(DOUBLEREQ) + doubleValue + '\n';
}