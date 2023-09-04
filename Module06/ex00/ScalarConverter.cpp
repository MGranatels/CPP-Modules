#include "ScalarConverter.hpp"

int	ScalarConverter::message(std::string type, std::string message) {
	std::cout << type << ": " << message << std::endl;
	return 1;
}

int	ScalarConverter::convertInt(std::string value)
{
	(void) value;

}

int	ScalarConverter::convertFloat(std::string value)
{
	(void) value;

}

int	ScalarConverter::convertDouble(std::string value)
{
	(void) value;
}

int	ScalarConverter::convertChar(std::string value)
{
	for (size_t i = 0; i < value.size(); i++)
		if (std::isdigit(value[i]))
            return (message("char", "Non displayable"));
	
	message ("char", value);
}