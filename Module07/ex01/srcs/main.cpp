#include <Iter.hpp>

void	increment(int &nb) {
	nb++;
}

void	decrement(int &nb) {
	nb--;
}

void	capitalize(std::string &str) {
	for (std::size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main( void ) {
	int a[5] = {1, 2, 3, 4, 5};
	int len = 5;

	std::string str[5] = {"Hello", "World", "I", "am", "here"};
    ::applier<std::string>(str, len, ::printElememts);
	std::cout << std::endl;
	
	::applier<std::string>(str, len, capitalize);
    ::applier<std::string>(str, len, ::printElememts);
	std::cout << std::endl;

    ::applier(a, len, increment);
    ::applier(a, len, increment);
 	::applier(a, len, ::printElememts);
    std::cout << std::endl;

    ::applier(a, len, decrement);
    ::applier(a, len, decrement);
 	::applier(a, len, ::printElememts);
    std::cout << std::endl;
	return 0;
}