#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <limits>

typedef struct Data
{
	std::string s1;
	int n;
} Data;

class	Serializer {
	private:

	public:
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer & operator=(const Serializer &assign);

		static size_t	serialize(Data* ptr);
		static	Data* deserialize(size_t raw);
};		
#endif