#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class	ScalarConverter {
	public:
		static	int	convertInt(std::string value);
		static	int	convertFloat(std::string value);
		static	int	convertDouble(std::string value);
		static	int	convertChar(std::string value);
		static	int	message(std::string type, std::string message);
};
#endif