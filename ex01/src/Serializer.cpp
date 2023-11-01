#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	serialize = reinterpret_cast<uintptr_t>(ptr);

	// std::memcpy(reinterpret_cast<void *>(&serialize), reinterpret_cast<void *>(ptr), sizeof(Data));
	return serialize;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*newData = reinterpret_cast<Data *>(raw);

	// *newData = *reinterpret_cast<Data *>(&raw);
	// std::memcpy(static_cast<void *>(newData), static_cast<void *>(&raw), sizeof(Data));
	return newData;
}
