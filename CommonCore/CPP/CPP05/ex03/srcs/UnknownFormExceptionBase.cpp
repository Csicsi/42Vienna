#include "UnknownFormExceptionBase.hpp"

const char *UnknownFormExceptionBase::what() const throw() {
	return "The intern does not know the form";
}
