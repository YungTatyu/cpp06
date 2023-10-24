#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>
#include <cmath>
#include <sstream>

const std::string	g_expect_char = "char: ";
const std::string	g_expect_int = "int: ";
const std::string	g_expect_float = "float: ";
const std::string	g_expect_double = "double: ";

#define POSITIVE_INF "+inf"
#define NEGATIVE_INF "-inf"
#define POSITIVE_INFF "+inff"
#define NEGATIVE_INFF "-inff"
#define NAND "nan"
#define NANF "nanf"

template <typename T>

static std::stirng	_getExpectCharValue(T input)
{
	if (
		input > static_cast<T>(std::numeric_limits<int>::max())
		|| input < static_cast<T>(std::numeric_limits<int>::min())
		|| static_cast<int>(input) > ASCII_NUM
		|| static_cast<int>(input) < 0
	)
		return "impossible";
	else
		return std::isprint(static_cast<unsigned char>(i)) ?
				static_cast<unsigned char>(i) : "Non displayable";
}
// template <typename T>

static std::stirng	_getExpectIntValue(T input)
{
	if (input > static_cast<T>(std::numeric_limits<int>::max())
		|| input < static_cast<T>(std::numeric_limits<int>::min()))
		return "impossible";
	std::stringstream ss;

	ss << static_cast<int>(input);
	return ss.str();
}

// template <typename T>

static std::stirng	_getExpectFloatValue(T input)
{
	if (input > static_cast<T>(std::numeric_limits<float>::max())
		|| input < static_cast<T>(std::numeric_limits<float>::min()))
		return "impossible";
	std::stringstream ss;

	ss << static_cast<float>(input);
	return ss.str() + "f";
}

// template <typename T>

static std::stirng	_getExpectFloatValue(T input)
{
	if (input > static_cast<T>(std::numeric_limits<double>::max())
		|| input < static_cast<T>(std::numeric_limits<double>::min()))
		return "impossible";
	std::stringstream ss;

	ss << static_cast<double>(input);
	return ss.str();
}

TEST(ScalarConverter_convertTest, intRange) {
	for (int i = INT_MIN; ; i++)
	{
		std::stringstream input;
		input << i;
		const float	fNum = static_cast<float>(i);
		const float	dNum = static_cast<double>(i);

		// if (i > ASCII_NUM || i < 0)
		// 	const std::stirng	expect_charValue = "impossible";
		// else
		// 	const std::stirng	expect_charValue = std::isprint(static_cast<unsigned char>(i)) ?
		// 		static_cast<unsigned char>(i) : "Non displayable";
		const std::stirng	expect_charValue = _getExpectCharValue<int>(i);

		std::stringstream ss;
		ss << fNum;
		const	std::stirng	expect_floatValue = ss.str() + ".0f";
		ss.str("");
		ss << dNum;
		const	std::stirng	expect_doubleValue = ss.str() + ".0";
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
		if (i == INT_MAX)
			break;
	}
}

TEST(ScalarConverter_convertTest, intOverFlow) {

	long	n = LONG_MAX;
	const float	fNum = static_cast<float>(n);
	const float	dNum = static_cast<double>(n);
	std::stringstream input;
	input << n;

	const std::stirng	expect_charValue = "impossible";
	std::stringstream ss;
	ss << fNum;
	const std::stirng	expect_floatValue = ss.str() + ".0f";
	ss.str("";)
	ss << dNum;
	const std::stirng	expect_doubleValue = ss.str() + ".0";
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(n.str());
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
}

TEST(ScalarConverter_convertTest, intUnderFlow) {

	long	n = LONG_MIN;
	const float	fNum = static_cast<float>(n);
	const float	dNum = static_cast<double>(n);
	std::stringstream input;
	input << n;

	const std::stirng	expect_charValue = "impossible";
	std::stringstream ss;
	ss << fNum;
	const std::stirng	expect_floatValue = ss.str() + ".0f";
	ss.str("";)
	ss << dNum;
	const std::stirng	expect_doubleValue = ss.str() + ".0";
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(n.str());
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
}

TEST(ScalarConverter_convertTest, nan) {

	const std::string	input = NAND;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = NANF;
	const std::stirng	expect_doubleValue = input;
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

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = input;
	const std::stirng	expect_doubleValue = NAND;
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


TEST(ScalarConverter_convertTest, +inf) {

	const std::string	input = POSITIVE_INF;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = POSITIVE_INFF;
	const std::stirng	expect_doubleValue = input;
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

TEST(ScalarConverter_convertTest, -inf) {

	const std::string	input = NEGATIVE_INF;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = NEGATIVE_INFF;
	const std::stirng	expect_doubleValue = input;
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

TEST(ScalarConverter_convertTest, +inff) {

	const std::string	input = POSITIVE_INFF;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = input;
	const std::stirng	expect_doubleValue = POSITIVE_INF;
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

TEST(ScalarConverter_convertTest, -inff) {

	const std::string	input = NEGATIVE_INFF;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_intValue = "impossible";
	const std::stirng	expect_floatValue = input;
	const std::stirng	expect_doubleValue = NEGATIVE_INF;
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

static void	_execTest(T input)
{
	std::stringstream ss;
	ss << input;
	const std::stirng	expect_charValue = _getExpectCharValue<T>(input);
	const std::stirng	expect_intValue = _getExpectIntValue<T>(input);
	const std::stirng	expect_floatValue = _getExpectDoubleValue<T>(input);
	const std::stirng	expect_doubleValue = _getExpectDoubleValue<T>(input);

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

	for (int i = 0; i < 100; i++)
	{
		_execTest<float>(negative);
		_execTest<float>(positive);
		if (i % 2 == 0)
		{
			negative /= 10.0f;
			positive /= 10.0f;
		}
		else
		{
			negative += 0.123456789f
			positive -= 0.123456789f
		}
	}
}

TEST(ScalarConverter_convertTest, doubleMaxMin) {

	double	negative = DBL_MIN;
	double	positive = DBL_MAX;

	for (int i = 0; i < 100; i++)
	{
		_execTest<double>(negative);
		_execTest<double>(positive);
		if (i % 2 == 0)
		{
			negative /= 10.0f;
			positive /= 10.0f;
		}
		else
		{
			negative += 0.123456789f
			positive -= 0.123456789f
		}
	}
}

TEST(ScalarConverter_convertTest, floatInput) {

	float	num = 0.0f;

	for (int i = 0; i < 100; i++)
	{
		_execTest<float>(num);
		nim += 1.5f;
	}
}

TEST(ScalarConverter_convertTest, doubleInput) {

	double	num = 0.0;

	for (int i = 0; i < 100; i++)
	{
		_execTest<double>(num);
		nim += 1.5;
	}
}

TEST(ScalarConverter_convertTest, charInput) {

	for (char i = ' '; i <= '~'; i++)
		_execTest<char>(i);
}
