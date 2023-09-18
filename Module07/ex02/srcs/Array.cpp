#include  <Array.hpp>

Array::Array(void) {
    std::cout << "\e[0;33mDefault Constructor called of Array\e[0m " << std::endl;
	
}

Array & Array::operator=(const Array &assign)
{
	(void)assign;
	return *this;
}

Array::Array(const Array& copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
}

Array::~Array() {
	std::cout << "\e[0;33mDestructer called of Array\e[0m" << std::endl;
}
