#include "../includes/Fixed.hpp"

int main() {
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

Fixed a(10);
const Fixed ca(10);
Fixed b(20);
const Fixed cb(20);
Fixed c(10.5f);
const Fixed cc(10.5f);
Fixed d(20.5f);
const Fixed cd(20.5f);

std::cout << "***int to int***" << std::endl;
std::cout << "10 < 20: " << (a < b ? "true" : "false" )<< std::endl;
std::cout << "20 < 10: " << (b < a ? "true" : "false" )<< std::endl;
std::cout << "10 > 20: " << (a > b ? "true" : "false" )<< std::endl;
std::cout << "20 > 10: " << (b > a ? "true" : "false" )<< std::endl;
std::cout << "10 <= 20: " << (a <= b ? "true" : "false" )<< std::endl;
std::cout << "10 <= 10: " << (a <= a ? "true" : "false" )<< std::endl;
std::cout << "10 >= 20: " << (a >= b ? "true" : "false" )<< std::endl;
std::cout << "10 >= 10: " << (a >= a ? "true" : "false" )<< std::endl;
std::cout << "10 == 20: " << (a == b ? "true" : "false" )<< std::endl;
std::cout << "10 == 10: " << (a == a ? "true" : "false" )<< std::endl;
std::cout << "10 != 20: " << (a != b ? "true" : "false" )<< std::endl;
std::cout << "10 != 10: " << (a != a ? "true" : "false" )<< std::endl;

std::cout << "\n***float to float***" << std::endl;
std::cout << "10.5 < 20.5: " << (c < d ? "true" : "false" )<< std::endl;
std::cout << "20.5 < 10.5: " << (d < c ? "true" : "false" )<< std::endl;
std::cout << "10.5 > 20.5: " << (c > d ? "true" : "false" )<< std::endl;
std::cout << "20.5 > 10.5: " << (d > c ? "true" : "false" )<< std::endl;
std::cout << "10.5 <= 20.5: " << (c <= d ? "true" : "false" )<< std::endl;
std::cout << "10.5 <= 10.5: " << (c <= c ? "true" : "false" )<< std::endl;
std::cout << "10.5 >= 20.5: " << (c >= d ? "true" : "false" )<< std::endl;
std::cout << "10.5 >= 10.5: " << (c >= c ? "true" : "false" )<< std::endl;
std::cout << "10.5 == 20.5: " << (c == d ? "true" : "false" )<< std::endl;
std::cout << "10.5 == 10.5: " << (c == c ? "true" : "false" )<< std::endl;
std::cout << "10.5 != 20.5: " << (c != d ? "true" : "false" )<< std::endl;
std::cout << "10.5 != 10.5: " << (c != c ? "true" : "false" )<< std::endl;

std::cout << "\n***int to float***" << std::endl;
std::cout << "10 < 20.5: " << (a < d ? "true" : "false" )<< std::endl;
std::cout << "20.5 < 10: " << (d < a ? "true" : "false" )<< std::endl;
std::cout << "10 > 20.5: " << (a > d ? "true" : "false" )<< std::endl;
std::cout << "20.5 > 10: " << (d > a ? "true" : "false" )<< std::endl;
std::cout << "10 <= 20.5: " << (a <= d ? "true" : "false" )<< std::endl;
std::cout << "10 <= 10: " << (a <= a ? "true" : "false" )<< std::endl;
std::cout << "10 >= 20.5: " << (a >= d ? "true" : "false" )<< std::endl;
std::cout << "10 >= 10: " << (a >= a ? "true" : "false" )<< std::endl;
std::cout << "10 == 20.5: " << (a == d ? "true" : "false" )<< std::endl;
std::cout << "10 == 10: " << (a == a ? "true" : "false" )<< std::endl;
std::cout << "10 != 20.5: " << (a != d ? "true" : "false" )<< std::endl;
std::cout << "10 != 10: " << (a != a ? "true" : "false" )<< std::endl;

std::cout << "\n***int and int***" << std::endl;
std::cout << "10 + 20: " << a + b << std::endl;
std::cout << "10 - 20: " << a - b << std::endl;
std::cout << "10 * 20: " << a * b << std::endl;
std::cout << "10 / 20: " << a / b << std::endl;

std::cout << "\n***float and float***" << std::endl;
std::cout << "10.5 + 20.5: " << c + d << std::endl;
std::cout << "10.5 - 20.5: " << c - d << std::endl;
std::cout << "10.5 * 20.5: " << c * d << std::endl;
std::cout << "10.5 / 20.5: " << c / d << std::endl;

std::cout << "\n***int and float***" << std::endl;
std::cout << "10 + 20.5: " << a + d << std::endl;
std::cout << "10 - 20.5: " << a - d << std::endl;
std::cout << "10 * 20.5: " << a * d << std::endl;
std::cout << "10 / 20.5: " << a / d << std::endl;

std::cout << "\n***int***" << std::endl;
std::cout << "a: " << a << std::endl;
std::cout << "++a: " << ++a << std::endl;
std::cout << "a: " << a << std::endl;
std::cout << "a++: " << a++ << std::endl;
std::cout << "a: " << a << std::endl;
a = 10;

std::cout << "\n***float***" << std::endl;
std::cout << "c: " << c << std::endl;
std::cout << "++c: " << ++c << std::endl;
std::cout << "c: " << c << std::endl;
std::cout << "c++: " << c++ << std::endl;
std::cout << "c: " << c << std::endl;
c = 10.5f;

std::cout << "\n***limit int and int***" << std::endl;
std::cout << "min(10, 20): " << Fixed::min(a, b) << std::endl;
std::cout << "max(10, 20): " << Fixed::max(a, b) << std::endl;
std::cout << "const min(10, 20): " << Fixed::min(ca, cb) << std::endl;
std::cout << "const max(10, 20): " << Fixed::max(ca, cb) << std::endl;
std::cout << "mix min(10, 20): " << Fixed::min(a, cb) << std::endl;
std::cout << "mix max(10, 20): " << Fixed::max(a, cb) << std::endl;

std::cout << "\n***limit float and float***" << std::endl;
std::cout << "min(10.5, 20.5): " << Fixed::min(c, d) << std::endl;
std::cout << "max(10.5, 20.5): " << Fixed::max(c, d) << std::endl;
std::cout << "const min(10.5, 20.5): " << Fixed::min(cc, cd) << std::endl;
std::cout << "const max(10.5, 20.5): " << Fixed::max(cc, cd) << std::endl;
std::cout << "mix min(10.5, 20.5): " << Fixed::min(c, cd) << std::endl;
std::cout << "mix max(10.5, 20.5): " << Fixed::max(c, cd) << std::endl;

std::cout << "\n***limit int and float***" << std::endl;
std::cout << "min(10, 20.5): " << Fixed::min(a, d) << std::endl;
std::cout << "max(10, 20.5): " << Fixed::max(a, d) << std::endl;
std::cout << "const min(10, 20.5): " << Fixed::min(ca, cd) << std::endl;
std::cout << "const max(10, 20.5): " << Fixed::max(ca, cd) << std::endl;
std::cout << "mix min(10, 20.5): " << Fixed::min(a, cd) << std::endl;
std::cout << "mix max(10, 20.5): " << Fixed::max(a, cd) << std::endl;

return 0;
}
