#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#define ASCII_NUM 127

class ScalarConverter
{
private:
	ScalarConverter();
public:
	static void	convert(const std::string& str);
	~ScalarConverter();
};

#endif