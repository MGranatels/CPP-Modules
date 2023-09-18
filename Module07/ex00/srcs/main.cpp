#include <Whatever.hpp>

int main( void ) {
	Whatever w;
	int a = 2;
	int b = 3;

	w.swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << w.min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << w.max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	w.swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << w.min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << w.max( c, d ) << std::endl;

	std::string str1 = "Aello";
	std::string str2 = "aello";
	std::cout << "max( Aello,  aello) = " << w.max( str1, str2 ) << std::endl;
	return 0;
}