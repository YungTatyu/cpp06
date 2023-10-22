#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "ScalarConverter.hpp"
#include <climits>

const std::string	g_expect_char = "char: ";
const std::string	g_expect_int = "int: ";
const std::string	g_expect_float = "float: ";
const std::string	g_expect_double = "double: ";

TEST(ScalarConverter_convertTest, intRange) {
	for (int i = INT_MIN; ; i++)
	{
		std::stringstream ss;
		ss << i;

		if (i > ASCII_NUM || i < 0)
			const std::stirng	expect_charValue = "impossible";
		else
			const std::stirng	expect_charValue = std::isprint(static_cast<unsigned char>i) ?
				static_cast<char>(i) : "Non displayable";
		const	std::stirng	expect_floatValue = ss.str() + ".0f";
		const	std::stirng	expect_doubleValue = ss.str() + ".0";
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		ScalarConverter::convert(ss.str());
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			g_expect_char + expect_charValue + '\n' +
			g_expect_int + ss.str() + '\n' +
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

	std::stringstream ss;
	ss << LONG_MAX;

	const std::stirng	expect_charValue = "impossible";
	const std::stirng	expect_floatValue = ss.str() + ".0f";
	const std::stirng	expect_doubleValue = ss.str() + ".0";
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	ScalarConverter::convert(ss.str());
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		g_expect_char + expect_charValue + '\n' +
		g_expect_int + ss.str() + '\n' +
		g_expect_float + expect_floatValue + '\n' +
		g_expect_double + expect_doubleValue + '\n',
		stdoutOutput
	);
	EXPECT_EQ("", stderrOutput);
}