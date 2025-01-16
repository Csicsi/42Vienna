#include "../includes/Utils.hpp"

bool getInput(const std::string &prompt, std::string &input) {
	std::cout << prompt;
	if (!std::getline(std::cin, input)) {
		std::cin.clear();
		std::cin.ignore(0, '\n');
		std::freopen("/dev/tty", "r", stdin);
		std::cerr << "\nInput interrupted. Operation aborted.\n";
		return false;
	}
	if (input == "") {
		std::cerr << "Must not be empty!" << std::endl;
		getInput(prompt, input);
	}
	return true;
}

bool getValidatedPhoneNumber(const std::string &prompt,
	std::string &phoneNumber) {
	if (!getInput(prompt, phoneNumber))
		return false;

	bool	isValid = true;
	size_t	i = 0;

	if (phoneNumber[0] == '+')
		i++;
	for (; i < phoneNumber.length(); i++) {
		if (!isdigit(phoneNumber[i])) {
			isValid = false;
			break;
		}
	}
	if (isValid && !phoneNumber.empty())
		return true;
	std::cerr << "Invalid phone number!"
		<< " Please enter a valid phone number" << std::endl;
	getValidatedPhoneNumber(prompt, phoneNumber);
	return true;
}

size_t ft_strlen(const std::string& str) {
	size_t charCount = 0;
	for (size_t i = 0; i < str.length();) {
		if ((str[i] & 0x80) == 0)
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		charCount++;
	}
	return charCount;
}

std::string turncate(std::string src) {
	std::ostringstream dest;
	size_t charCount = ft_strlen(src);

	if (charCount < 10) {
		size_t padCount = 10 - charCount;
		dest << std::string(padCount, ' ') << src;
		src = dest.str();
	} else if (charCount > 10) {
		size_t charCounter = 0;
		size_t byteIndex = 0;

		while (charCounter < 9 && byteIndex < src.length()) {
			if ((src[byteIndex] & 0x80) == 0)
				byteIndex += 1;
			else if ((src[byteIndex] & 0xE0) == 0xC0)
				byteIndex += 2;
			else if ((src[byteIndex] & 0xF0) == 0xE0)
				byteIndex += 3;
			else if ((src[byteIndex] & 0xF8) == 0xF0)
				byteIndex += 4;
			charCounter++;
		}
		src = src.substr(0, byteIndex) + ".";
	}
	return src;
}
