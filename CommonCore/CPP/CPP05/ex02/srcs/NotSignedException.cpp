#include "NotSignedException.hpp"

const char* NotSignedException::what() const throw() {
	return "Form is not signed";
}
