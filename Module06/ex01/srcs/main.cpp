#include <Serializer.hpp>

int main ()
{
	Data *data = new Data;
	data->n = 423;
	data->s1 = "Badgelgeh";
	Data *testing;

	uintptr_t raw = Serializer::serialize(data);

	std::cout << data->n << " " << data->s1 << std::endl;
	std::cout << "Adress of Data Struct: " << data << std::endl;
	std::cout << "Serialized Adress of Data Struct: " << raw << std::endl;

	std::cout << "Deserialized Adress of Data Struct: " << Serializer::deserialize(raw) << std::endl;
	testing = Serializer::deserialize(raw);
	std::cout << "Testing Adress of Data Struct: " << testing << std::endl;
	std::cout << "Data Adress of Data Struct: " << data << std::endl;
	
	std::cout << data->n << " " << data->s1 << std::endl;
	
	delete data;
}