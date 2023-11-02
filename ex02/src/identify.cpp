#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

Base	*generate(void)
{
	std::srand(std::time(NULL));
	const int	num = std::rand() % 3;
	Base	*ptr;

	switch (num)
	{
	case 0:
		ptr = new A();
		std::cout << "A generated" << std::endl;
		break;
	case 1:
		ptr = new B();
		std::cout << "B generated" << std::endl;
		break;
	case 2:
		ptr = new C();
		std::cout << "C generated" << std::endl;
		break;
	default:
		ptr = new Base();
		std::cout << "Base generated" << std::endl;
		break;
	}
	return ptr;
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "The actual type is A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "The actual type is B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "The actual type is C" << std::endl;
	else
		std::cout << "The actual type is Base" << std::endl;
}

template <typename T>
bool	_isType(Base& p)
{
	try
	{
		const T	convertedPtr = dynamic_cast<T &>(p);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

void	identify(Base& p)
{
	if (_isType<A>(p))
		std::cout << "The actual type is A" << std::endl;
	else if (_isType<B>(p))
		std::cout << "The actual type is B" << std::endl;
	else if (_isType<C>(p))
		std::cout << "The actual type is C" << std::endl;
	else
		std::cout << "The actual type is Base" << std::endl;
}
