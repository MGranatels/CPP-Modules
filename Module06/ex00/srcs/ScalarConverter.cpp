#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter() {
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}

// Operators
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &assign) {
	(void) assign;
	return *this;
}

void	ScalarConverter::converter(int value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::converter(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::converter(double value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	if (value >  std::numeric_limits<int>::max() || value <  std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value > static_cast<double>(std::numeric_limits<float>::max()) || value < static_cast<double>(-FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::converter(float value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	if (value > static_cast<float>(std::numeric_limits<int>::max()) || value < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::impossible()
{
	std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;

	exit(1);
}

void	ScalarConverter::ScalarConverter::displayValues(std::string Flimit, std::string Dlimit)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << Flimit << std::endl;
	std::cout << "double: " << Dlimit << std::endl;

	exit(1);
}

void	ScalarConverter::converterType(std::string value)
{
	const std::string existingTypes[4] = {"int", "char", "float", "double"};
	std::string type = getType(value);
	
	int i = 0;

	while (i < 4 && existingTypes[i].compare(type))
		i++;
	switch (i + 1) {
	case 1:
	{
		std::istringstream numberStream(value);
		int	valueInt;
		numberStream >> valueInt; 
		return converter(valueInt);
	}
	case 2:
		return converter(value[0]);
	case 3:
	{
		std::istringstream numberStream(value);
		float	valueFloat;
		numberStream >> valueFloat; 
		return converter(valueFloat);
	}
	case 4:
	{
		std::istringstream numberStream(value);
		double	valueDouble;
		numberStream >> valueDouble; 
		return converter(valueDouble);
	}
	}
}

void	ScalarConverter::converter(std::string value)
{
	const std::string Flimits[4] = {"inff", "-inff", "+inff", "nanf"};
	const std::string Dlimits[4] = {"inf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 4; i++ )
	{
		if (value == Flimits[i] || value == Dlimits[i])
			displayValues(Flimits[i], Dlimits[i]);
	}
	converterType(value);
}

std::string	ScalarConverter::getType(std::string value)
{
	int	dot = 0, minus = 0, plus = 0, ifloat = 0, ichar = 0;
	if (value.empty())
		impossible();
	for (size_t i = 0; i < value.size(); i++)
	{
		dot += (value[i] == '.');
		minus += (value[i] == '-');
		plus += (value[i] == '+');
		ifloat += (value[i] == 'f');
		if(std::isalpha(value[i]))
			ichar++;
		if (!std::isalpha(value[i]) && !std::isdigit(value[i]) && value[i] != '.' \
		&& value[i] != '+' && value[i] != '-')
			impossible();
		if ((value[i] == 'f' && i != value.size() - 1) \
		|| (value[i] == '.' && i == value.size() - 1) \
		|| (value[i] == '-' && i != 0) \
		|| (value[i] == '+' && i != 0 ) \
		|| dot > 1 || minus > 1 || plus > 1 || ifloat > 1)
			impossible();
	}
	if (value.size() == 1 && !std::isdigit(value[0]))
		return ("char");
	else if (dot && ifloat && ichar == 1)
	{
		if ((value[value.size() - 2] == '.' && !value[value.size() - 3]) \
		|| (value[value.size() - 2] == '.' && value[value.size() - 3] == '+')
		|| (value[value.size() - 2] == '.' && value[value.size() - 3] == '-'))
			impossible();
		return ("float");
	}
	else if (ichar >= 1)
		impossible();
	else if (!dot && !ifloat && value.size() >= 10)
	{
		if ((minus && value.size() == 11 && value.compare("-2147483648") > 0)
		|| (minus && value.size() > 11))
			return "double";
		else if ((plus && value.size() == 11 && value.compare("+2147483647") > 0) \
		|| (plus && value.size() == 11 && value.compare("+2147483647") > 0))
			return "double";
		else if (!minus && !plus && value.size() == 10 && value.compare("2147483647") > 0)
			return "double";
		else if (!minus && !plus && value.size() > 10)
			return "double";
		return ("int");
	}
	if (dot == 1)
		return ("double");
	return ("int");

}

