#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#define ASCII_NUM 127

class ScalarConverter
{
private:
	ScalarConverter();
	enum type {
		TP_CHAR,
		TP_INT,
		TP_FLOAT,
		TP_DOUBLE,
	};
	enum type _getStringType(const std::string& str);
	void	_convertChar(char& c);
	void	_convertInt(int& num);
	void	_convertFloat(float& num);
	void	_convertDouble(double& num);
public:
	static void	convert(const std::string& str);
};

#endif