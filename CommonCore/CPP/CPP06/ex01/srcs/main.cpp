#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.s1 = "Hello, world!";
	data.n = 42;
	data.f = 3.14f;

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "original: " << &data << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;
	std::cout << "Same pointer? " << (&data == deserialized ? "Yes" : "No") << std::endl;

	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "f: " << deserialized->f << std::endl;

	return 0;
}
