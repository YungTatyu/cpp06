#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>
#include <cmath>
#include <sstream>
#include <vector>

const std::string	g_expect_char = "char: ";
const std::string	g_expect_int = "int: ";
const std::string	g_expect_float = "float: ";
const std::string	g_expect_double = "double: ";

#define POSITIVE_INF "+inf"
#define INF "inf"
#define NEGATIVE_INF "-inf"
#define POSITIVE_INFF "+inff"
#define NEGATIVE_INFF "-inff"
#define INFF "inff"
#define NAND "nan"
#define NANF "nanf"

template <typename T>
static std::string	_getExpectCharValue(T input)
{
	const T	max = static_cast<T>(std::numeric_limits<int>::max());
	const T	min = static_cast<T>(std::numeric_limits<int>::min());

	if (
		input > max
		|| input < min
		|| static_cast<int>(input) > ASCII_NUM
		|| static_cast<int>(input) < 0
	)
		return IMPOSSIBLE;
	else
		return std::isprint(static_cast<int>(input)) ?
				std::string(1, static_cast<char>(input)) : "Non displayable";
}

template <typename T>
static std::string	_getExpectIntValue(T input)
{
	const T	max = static_cast<T>(std::numeric_limits<int>::max());
	const T	min = static_cast<T>(std::numeric_limits<int>::min());

	if (input > max || input < min)
		return IMPOSSIBLE;
	std::stringstream ss;

	ss << static_cast<int>(input);
	return ss.str();
}

template <typename T>
static std::string	_getExpectFloatValue(T input)
{
	std::stringstream ss;

	ss << static_cast<float>(input);
	return ss.str();
}

template <typename T>
static std::string	_getExpectDoubleValue(T input)
{
	std::stringstream ss;

	ss << static_cast<double>(input);
	return ss.str();
}

std::string	_appendDecimal(const std::string& str)
{
	if (
		str.find("nan") != std::string::npos ||
		str.find("inf") != std::string::npos ||
		str.find(".") != std::string::npos
	)
		return str;
	else
		return str + ".0";
}

TEST(ScalarConverter_convertTest, intMin) {

	int	i = INT_MIN;

	while (true)
	{
		std::stringstream input;
		input << i;
		const float	fNum = static_cast<float>(i);
		const float	dNum = static_cast<double>(i);

		const std::string	expect_charValue = _getExpectCharValue<int>(i);

		std::stringstream ss;
		ss << fNum;
		const	std::string	expect_floatValue = _appendDecimal(ss.str()) + "f";
		ss.str("");
		ss << dNum;
		const	std::string	expect_doubleValue = _appendDecimal(ss.str());
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(input.str());
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + expect_charValue + '\n' +
			g_expect_int + input.str() + '\n' +
			g_expect_float + expect_floatValue + '\n' +
			g_expect_double + expect_doubleValue + '\n',
			stdoutOutput
		);
		EXPECT_EQ("", stderrOutput);
		if (i == INT_MIN + 100)
			break;
		i++;
	}
}

TEST(ScalarConverter_convertTest, intMax) {

	int	i = INT_MAX;

	while (true)
	{
		std::stringstream input;
		input << i;
		const float	fNum = static_cast<float>(i);
		const float	dNum = static_cast<double>(i);

		const std::string	expect_charValue = _getExpectCharValue<int>(i);
		std::stringstream ss;
		ss << fNum;
		const	std::string	expect_floatValue = _appendDecimal(ss.str()) + "f";
		ss.str("");
		ss << dNum;
		const	std::string	expect_doubleValue = _appendDecimal(ss.str());
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(input.str());
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + expect_charValue + '\n' +
			g_expect_int + input.str() + '\n' +
			g_expect_float + expect_floatValue + '\n' +
			g_expect_double + expect_doubleValue + '\n',
			stdoutOutput
		);
		EXPECT_EQ("", stderrOutput);
		if (i == INT_MAX - 100)
			break;
		i--;
	}
}

TEST(ScalarConverter_convertTest, intZero) {

	int	i = -100;

	while (true)
	{
		std::stringstream input;
		input << i;
		const float	fNum = static_cast<float>(i);
		const float	dNum = static_cast<double>(i);

		const std::string	expect_charValue = _getExpectCharValue<int>(i);
		std::stringstream ss;
		ss << fNum;
		const	std::string	expect_floatValue = _appendDecimal(ss.str()) + "f";
		ss.str("");
		ss << dNum;
		const	std::string	expect_doubleValue = _appendDecimal(ss.str());
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(input.str());
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + expect_charValue + '\n' +
			g_expect_int + input.str() + '\n' +
			g_expect_float + expect_floatValue + '\n' +
			g_expect_double + expect_doubleValue + '\n',
			stdoutOutput
		);
		EXPECT_EQ("", stderrOutput);
		if (i == 100)
			break;
		i++;
	}
}

TEST(ScalarConverter_convertTest, intOverFlow) {

	long	n = LONG_MAX;
	const float	fNum = static_cast<float>(n);
	const float	dNum = static_cast<double>(n);
	std::stringstream input;
	input << n;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	std::stringstream ss;
	ss << fNum;
	const std::string	expect_floatValue = _appendDecimal(ss.str()) + "f";
	ss.str("");
	ss << dNum;
	const std::string	expect_doubleValue = _appendDecimal(ss.str());
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input.str());
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

TEST(ScalarConverter_convertTest, intUnderFlow) {

	long	n = LONG_MIN;
	const float	fNum = static_cast<float>(n);
	const float	dNum = static_cast<double>(n);
	std::stringstream input;
	input << n;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	std::stringstream ss;
	ss << fNum;
	const std::string	expect_floatValue = _appendDecimal(ss.str()) + "f";
	ss.str("");
	ss << dNum;
	const std::string	expect_doubleValue = _appendDecimal(ss.str());
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input.str());
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

TEST(ScalarConverter_convertTest, nan) {

	const std::string	input = NAND;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = NANF;
	const std::string	expect_doubleValue = NAND;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}


TEST(ScalarConverter_convertTest, nanf) {

	const std::string	input = NANF;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = NANF;
	const std::string	expect_doubleValue = NAND;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}


TEST(ScalarConverter_convertTest, pInf) {

	const std::string	input = POSITIVE_INF;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = INFF;
	const std::string	expect_doubleValue = INF;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

TEST(ScalarConverter_convertTest, nInf) {

	const std::string	input = NEGATIVE_INF;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = NEGATIVE_INFF;
	const std::string	expect_doubleValue = NEGATIVE_INF;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

TEST(ScalarConverter_convertTest, pInff) {

	const std::string	input = POSITIVE_INFF;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = INFF;
	const std::string	expect_doubleValue = INF;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

TEST(ScalarConverter_convertTest, nInff) {

	const std::string	input = NEGATIVE_INFF;

	const std::string	expect_charValue = IMPOSSIBLE;
	const std::string	expect_intValue = IMPOSSIBLE;
	const std::string	expect_floatValue = NEGATIVE_INFF;
	const std::string	expect_doubleValue = NEGATIVE_INF;
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(input);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}

template <typename T>
static void	_execTest(T input)
{
	std::stringstream ss;
	ss << input;
	const std::string	expect_charValue = _getExpectCharValue<T>(input);
	const std::string	expect_intValue = _getExpectIntValue<T>(input);
	const std::string	expect_floatValue = _appendDecimal(_getExpectFloatValue<T>(input)) + "f";
	const std::string	expect_doubleValue = _appendDecimal(_getExpectDoubleValue<T>(input));

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(ss.str());
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
}

template <typename T>
static void	_execFloatTest(T input)
{
	std::stringstream ss;
	ss << input;
	const std::string	expect_charValue = _getExpectCharValue<T>(input);
	const std::string	expect_intValue = _getExpectIntValue<T>(input);
	const std::string	expect_floatValue = _appendDecimal(_getExpectFloatValue<T>(input)) + "f";
	const std::string	expect_doubleValue = _appendDecimal(_getExpectDoubleValue<T>(input));

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(ss.str());
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + expect_intValue + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
}

TEST(ScalarConverter_convertTest, floatMaxMin) {

	float	negative = FLT_MIN;
	float	positive = FLT_MAX;

	for (int i = 0; i < 10; i++)
	{
		_execTest<float>(negative);
		_execTest<float>(positive);
		if (i % 2 == 0)
		{
			negative *= 10.0f;
			positive /= 10.0f;
		}
		else
		{
			negative += 0.0000000000000000123456789f;
			positive -= 0.0000000000000000123456789f;
		}
	}
}

TEST(ScalarConverter_convertTest, doubleMaxMin) {

	double	negative = DBL_MIN;
	double	positive = DBL_MAX;

	for (int i = 0; i < 5; i++)
	{
		_execTest<double>(negative);
		_execTest<double>(positive);
		if (i % 2 == 0)
		{
			negative *= 10.0;
			positive /= 10.0;
		}
		else
		{
			negative += 0.0000000000000000123456789;
			positive -= 0.0000000000000000123456789;
		}
	}
}

TEST(ScalarConverter_convertTest, floatInput) {

	float	num = 0.0f;

	for (int i = 0; i < 100; i++)
	{
		std::string	input = ScalarConverter::convertToString<float>(num);
		input += "f";
		const std::string	expect_charValue = _getExpectCharValue<float>(num);
		const std::string	expect_intValue = _getExpectIntValue<float>(num);
		const std::string	expect_floatValue = _appendDecimal(_getExpectFloatValue<float>(num)) + "f";
		const std::string	expect_doubleValue = _appendDecimal(_getExpectDoubleValue<float>(num));

		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(input);
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + expect_charValue + '\n' +
			g_expect_int + expect_intValue + '\n' +
			g_expect_float + expect_floatValue + '\n' +
			g_expect_double + expect_doubleValue + '\n',
			stdoutOutput
		);

		num += 1.5f;
	}
}

TEST(ScalarConverter_convertTest, doubleInput) {

	double	num = 0.0;

	for (int i = 0; i < 100; i++)
	{
		// _execTest<double>(num);
		_execFloatTest<double>(num);
		if (i % 10 == 0)
			num += 0.1;
		else
			num += 0.3;
	}
}

TEST(ScalarConverter_convertTest, charInput) {

	for (char i = ' '; i <= '~'; i++)
		_execTest<char>(i);
}

TEST(ScalarConverter_convertTest, stringInput) {

	const std::vector<std::string>	v = {"", "test", " ", "	 	", "	", NULL, nullptr};

	for (auto it = v.begin(); it != v.end(); it++)
	{
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(*it);
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + IMPOSSIBLE + '\n' +
			g_expect_int + IMPOSSIBLE + '\n' +
			g_expect_float + IMPOSSIBLE + '\n' +
			g_expect_double + IMPOSSIBLE + '\n',
			stdoutOutput
		);
		EXPECT_EQ("", stderrOutput);
	}
}
