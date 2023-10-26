#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#define ASCII_NUM 127

template<typename T, typename T1>
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
	enum type _getStringType(const std::string& str) const;
	void	_convertChar(char& c) const;
	void	_convertInt(int& num) const;
	void	_convertFloat(float& num) const;
	void	_convertDouble(double& num) const;
	bool	_isConvertibleToAscii(const std::string& str) const;
	bool	_isConvertible(const std::string& str) const;
	void	_print(const std::string& charValue, const std::string& intValue,
			const std::string& floatValue, const std::string& doubleValue);
	std::string	_getCharValue(int& num);
	std::string	_getIntValue(T num);
	std::string	_getFloatValue(T1 num);
public:
	static void	convert(const std::string& str);
	static T	stringToType(const std::string& str)
	{
		std::istringstream iss(str);
		T	value;

		iss >> value;
		return value;
	}
};

#endif