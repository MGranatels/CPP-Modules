#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class	ScalarConverter {
	public:
		static	int		convertInt(std::string value);
		static	int		convertFloat(std::string value);
		static	int		convertDouble(std::string value);
		static	int		convertChar(std::string value);
		static	void	displayValues(std::string type, std::string message);
};
#endif