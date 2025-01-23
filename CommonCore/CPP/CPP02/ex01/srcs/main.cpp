#include "../includes/Fixed.hpp"

#define FIXED_MAX 8388607
#define FIXED_MIN -8388608

int main( void ) {
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

Fixed e(0);
std::cout << "0 is " << e << std::endl;
std::cout << "0 is " << e.toInt() << " as integer" << std::endl;
Fixed f(-42.42f);
std::cout << "-42.42f is " << f << std::endl;
std::cout << "-42.42f is " << f.toInt() << " as integer" << std::endl;
Fixed g(FIXED_MAX);
std::cout << "FIXED_MAX is " << g << std::endl;
std::cout << "FIXED_MAX is " << g.toInt() << " as integer" << std::endl;
Fixed h(FIXED_MIN);
std::cout << "FIXED_MIN is " << h << std::endl;
std::cout << "FIXED_MIN is " << h.toInt() << " as integer" << std::endl;
Fixed i(FIXED_MAX + 1);
std::cout << "FIXED_MAX + 1 is " << i << std::endl;
std::cout << "FIXED_MAX + 1 is " << i.toInt() << " as integer" << std::endl;
Fixed j(FIXED_MIN - 1);
std::cout << "FIXED_MIN - 1 is " << j << std::endl;
std::cout << "FIXED_MIN - 1 is " << j.toInt() << " as integer" << std::endl;
Fixed k(0.0001f);
std::cout << "0.0001f is " << k << std::endl;
std::cout << "0.0001f is " << k.toInt() << " as integer" << std::endl;
Fixed l(8388606.999f);
std::cout << "8388606.999f is " << l << std::endl;
std::cout << "8388606.999f is " << l.toInt() << " as integer" << std::endl;
Fixed m(8388607.999f);
std::cout << "8388607.999f is " << l << std::endl;
std::cout << "8388607.999f is " << l.toInt() << " as integer" << std::endl;
Fixed n(-8388608.001f);
std::cout << "-8388608.001f is " << n << std::endl;
std::cout << "-8388608.001f is " << n.toInt() << " as integer" << std::endl;
Fixed o(-8388609.001f);
std::cout << "-8388609.001f is " << o << std::endl;
std::cout << "-8388609.001f is " << o.toInt() << " as integer" << std::endl;

return 0;
}
