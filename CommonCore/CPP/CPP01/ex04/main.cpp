#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(const std::string& inputFilename,
	const std::string& s1, const std::string& s2) {
	std::ifstream inputFile(inputFilename.c_str());
	if (!inputFile) {
		std::cerr << "Error: Could not open input file!" << std::endl;
		return;
	}

	std::string outputFilename = inputFilename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile) {
		std::cerr << "Error: Could not create output file!" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << '\n';
	}

	std::cout << "Replacement completed." << std::endl;

	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>"
			<< std::endl;
		return 1;
	}

	std::string inputFilename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty()) {
		std::cerr << "Error: Strings s1 and s2 must not be empty."
			<< std::endl;
		return 1;
	}

	replaceAndWrite(inputFilename, s1, s2);

	return 0;
}
