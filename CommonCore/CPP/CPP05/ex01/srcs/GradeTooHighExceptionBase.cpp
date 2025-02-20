#include "GradeTooHighExceptionBase.hpp"

const char *GradeTooHighExceptionBase::what() const throw() {
	return "Grade is too high";
}
