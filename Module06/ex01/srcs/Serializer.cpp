#include <Serializer.hpp>

Serializer::Serializer() {
	std::cout << "\e[0;33mDefault Constructor called of Serializer\e[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Serializer\e[0m" << std::endl;
}

// Destructor
Serializer::~Serializer() {
	std::cout << "\e[0;31mDestructor called of Serializer\e[0m" << std::endl;
}

size_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<size_t>(ptr);
}

Data*	Serializer::deserialize(size_t raw) {
	 return reinterpret_cast<Data*>(raw);
}

