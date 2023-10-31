#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();
	Serializer&	operator=(const Serializer& other);
public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif
