#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	d;
	d.name = "tachu";
	d.id = 1;

	uintptr_t	serialize = Serializer::serialize(&d);
	Data	*ptr = Serializer::deserialize(serialize);
	std::cout << serialize << '\n'
		<< ptr->name << '\n'
		<< ptr->id << '\n'
		<< ptr->buffer << '\n';
}