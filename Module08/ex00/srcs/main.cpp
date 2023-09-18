#include <Easyfind.hpp>

int	main(void)
{
	int	arr[9] = {0, 23, 4, 53, 3, 34, 33, 2, 1};
	std::vector<int> vec(arr, arr  + (sizeof(arr) / sizeof(int)));
	std::cout << *easyfind(vec, 2) << std::endl;
	try {
		std::cout << *easyfind(vec, 567) << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Exception: 567: " << e.what() << std::endl;
    }

	std::string abc = "abcdefgijklmnopqrstuvwxyz";
	std::vector<char> checkChar(abc.begin(), abc.end());
	std::cout << *easyfind(checkChar, 'w') << std::endl;
	try {
		std::cout << *easyfind(vec, 'h') << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Exception: h: " << e.what() << std::endl;
    }
	try {
		std::cout << *easyfind(vec, '2') << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Exception: 2: " << e.what() << std::endl;
    }
}