#include "../include/utility.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

// function to identify 'mul(a,b)'
// 'mul(a,b)' accepts upto 3 digit integer
void parseData( const std::string& data) {
	
	// regex pattern
	std::regex pattern(R"(\b(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\)))");
	std::smatch matches;
	int totalResult = 0;
	bool mulEnabled = true;
	std::string::const_iterator searchStart(data.begin());

	while (std::regex_search(searchStart, data.end(), matches, pattern)) {
		if (matches[1] == "do()") {
			mulEnabled = true;
		} else if (matches[1] == "don't()") {
			mulEnabled = false;
		} else if (mulEnabled && matches[2].matched && matches[3].matched) {
			int num1 = std::stoi(matches[2].str());
			int num2 = std::stoi(matches[3].str());
			int result = num1 * num2;
			totalResult += result;
		}
		searchStart = matches.suffix().first;
	}
	std::cout << "\033[32mThe result is: " << totalResult << ".\033[0m\n";
}

// function to load a file
void processFile(const std::string& filePath) {
	
	std::fstream file(filePath);
	std::stringstream buffer;

	if (!file.is_open()) {
		std::cerr << "\033[31mError: File could not be opened.\033[0m\n";
		return;
	} else {
		std::cout << "\033[32m[DEBUG] Successfully loaded!\033[0m\n";
	}

	buffer << file.rdbuf();
	std::string data = buffer.str();
	file.close();

	parseData(data);
}


