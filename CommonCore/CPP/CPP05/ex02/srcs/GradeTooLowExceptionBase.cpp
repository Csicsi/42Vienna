#include "GradeTooLowExceptionBase.hpp"

const char *GradeTooLowExceptionBase::what() const throw() {
	return "Grade is too low";
}
