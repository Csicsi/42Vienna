#include "NotSignedExceptionBase.hpp"

const char *NotSignedExceptionBase::what() const throw() {
	return "Form has not been signed yet.";
}
