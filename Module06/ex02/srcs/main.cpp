#include "Base.hpp"
#include <iostream>

int main()
{
	Base *base = NULL;
	base = base->generate();
	std::cout << "ID by ptr: "; 
	base->identify(base);
	std::cout << "ID by ref: "; 
	base->identify(base);
	delete base;
}