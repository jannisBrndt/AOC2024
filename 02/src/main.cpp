#include "../include/utility.h"
#include <vector>

int main() {
	
	const std::string& filePath = "../assets/puzzle_input.txt";

	auto data = readData(filePath);

	checkData(data);

	return 0;

}
