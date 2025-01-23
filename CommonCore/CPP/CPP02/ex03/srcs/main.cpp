#include "../includes/Point.hpp"

int main() {
Point a(0, 5);
Point b(5, 0);
Point c(0, 0);
Point in(2, 2);
Point out(10, 10);
Point edge(0, 3);

std::cout << "Point (2, 2) is: " << (bsp(a, b, c, in) ? "inside" : "outside") << std::endl;
std::cout << "Point (10, 10) is: " << (bsp(a, b, c, out) ? "inside" : "outside") << std::endl;
std::cout << "Point (0, 3) is: " << (bsp(a, b, c, edge) ? "inside" : "outside") << std::endl;

return 0;
}
