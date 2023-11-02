#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

TEST(Identify_test, identifyPtr_test) {

	for (size_t i = 0; i < 100; i++)
	{
		testing::internal::CaptureStdout();
		Base	*ptr = generate();
		std::string	g_stdoutOutput = testing::internal::GetCapturedStdout();
		testing::internal::CaptureStdout();
		identify(ptr);
		std::string	i_stdoutOutput = testing::internal::GetCapturedStdout();

		if (
			(g_stdoutOutput.find("A") != std::string::npos && i_stdoutOutput.find("A") != std::string::npos) ||
			(g_stdoutOutput.find("B") != std::string::npos && i_stdoutOutput.find("B") != std::string::npos) ||
			(g_stdoutOutput.find("C") != std::string::npos && i_stdoutOutput.find("C") != std::string::npos)
		)
			SUCCEED();
		else
			FAIL() << "test failed";
	}
}
