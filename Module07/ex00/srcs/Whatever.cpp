#include <Whatever.hpp>


Whatever::Whatever(void) {
    std::cout << "\e[0;33mDefault Constructor called of Whatever\e[0m " << std::endl;
}

Whatever & Whatever::operator=(const Whatever &assign)
{
	(void)assign;
	return *this;
}

Whatever::Whatever(const Whatever& copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Whatever\e[0m" << std::endl;
}

Whatever::~Whatever() {
	std::cout << "\e[0;33mDestructer called of Whatever\e[0m" << std::endl;
}
