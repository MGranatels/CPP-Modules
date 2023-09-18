#include "Array.hpp"

int main()
{
	Array <int> a(20);
	Array <int> mirror(20);
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		const int n = rand();
		std::cout << "n: " << n << std::endl; 
		a[i] = n;
	}
	std::cout << "DEBUG" << std::endl;
	try {
		a[6] = 1;
	}    
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "DEBUG2" << std::endl;
	a = mirror;
	std::cout << "DEBUG3" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << "Mirror: " << mirror[i] << std::endl;
		std::cout << "A: " << a[i] << std::endl;
	}
	//a.printArray();
}