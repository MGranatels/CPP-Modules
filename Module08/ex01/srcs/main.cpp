#include <Span.hpp>

int	main ()
{
	Span letzzGo(10000);
	
	try {
		letzzGo.shortestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
	try {
		letzzGo.addListNumber(10000);
	}
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	try {
		letzzGo.addListNumber(5);
	}
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	for (unsigned int i = 0;  i < letzzGo.getVector().size(); i++)
		std::cout << "Vector: " << letzzGo.getVector()[i] << std::endl;
	std::cout << "Vector size: " << letzzGo.getVector().size() <<  std::endl;
	std::cout << "Shortest Span for letzzGo: " << letzzGo.shortestSpan() << std::endl;
	std::cout  << "Longest Span for letzzGo: " << letzzGo.longestSpan() << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span for sp: " << sp.shortestSpan() << std::endl;
	std::cout  << "Longest Span for sp: " << sp.longestSpan() << std::endl;
}