#include "whatever.hpp"
#include <iostream>

template<typename T> void testTemplate(T a, T b) {
	std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

int main( void ) {
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
{
	std::cout << "\nfloat:" << std::endl;
	testTemplate(2.5f, 3.5f);
	std::cout << "\nchar:" << std::endl;
	testTemplate('a', 'b');
	std::cout << "\nints:" << std::endl;
	testTemplate(-3, 2);
	testTemplate(3, 3);
	std::cout << "\nstrings:" << std::endl;
	testTemplate("same", "same");
	testTemplate("", "");
	testTemplate("", "not empty");
}
return 0;
}
