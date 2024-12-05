// main file
#include "../include/utility.h"
#include <iostream>

int main() {

	std::string filePath = "../assets/puzzle_input.txt";
	std::string word = "XMAS";
	auto grid = loadFile(filePath);
	int count = countOccurrences(grid, word);

	std::cout << "The word " << word << " appears " << count << " times.\n";
	return 0;
}
