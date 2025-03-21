#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::exception &e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

Base* generate(void) {
	std::srand(std::time(NULL));
	int r = std::rand() % 3;
	switch (r) {
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}

int main() {
	Base *p = generate();
	Base &r = *p;

	std::cout << "Pointer: ";
	identify(p);
	std::cout << "Reference: ";
	identify(r);

	delete p;
	return 0;
}
