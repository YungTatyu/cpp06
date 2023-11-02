
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
void	_identify(Base* p)
{
	if (static_cast<A *>(p) != NULL)
		std::cout << "The actual type is A" << std::endl;
	else if (static_cast<B *>(p) != NULL)
		std::cout << "The actual type is B" << std::endl;
	else if (static_cast<C *>(p) != NULL)
		std::cout << "The actual type is C" << std::endl;
	else
		std::cout << "The actual type is Base" << std::endl;
}

int	main()
{
	Base	*ptr = generate();
	identify(ptr);
	identify(*ptr);
	_identify(ptr);
	return 0;
}