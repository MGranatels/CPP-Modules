#include <Iter.hpp>


Iter::Iter(void) {
    std::cout << "\e[0;33mDefault Constructor called of Iter\e[0m " << std::endl;
}

Iter & Iter::operator=(const Iter &assign)
{
	(void)assign;
	return *this;
}

Iter::Iter(const Iter& copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Iter\e[0m" << std::endl;
}

Iter::~Iter() {
	std::cout << "\e[0;33mDestructer called of Iter\e[0m" << std::endl;
}