#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Serializer.hpp"
#include "Data.hpp"

#include <string>


TEST(Serializer_test, serialize) {

	for (int i = 0; i < 100; i++)
	{
		Data	d;

		d.buffer = "buffer" + std::to_string(i);
		d.name = "tachu" + std::to_string(i);
		d.id = static_cast<uint64_t>(i);

		const uint64_t	serial = Serializer::serialize(&d);
		Data	*ptr = Serializer::deserialize(serial);

		EXPECT_EQ(d.name, ptr->name);
		EXPECT_EQ(d.buffer, ptr->buffer);
		EXPECT_EQ(d.id, ptr->id);
	}
}
