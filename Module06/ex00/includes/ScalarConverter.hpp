#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cfloat>

class	ScalarConverter {
	private:
		static void			converter(int value);
		static void			converter(float value);
		static void			converter(double value);
		static void			impossible(void);
		static std::string	getType(std::string value);
		static void			converter(char value);
		static void			converterType(std::string value);
		static void			displayValues(std::string Flimit, std::string Dlimit);

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &assign);

		static void	converter(std::string value);
};		
#endif