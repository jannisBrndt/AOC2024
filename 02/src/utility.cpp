#include "../include/utility.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> readData(const std::string& filePath) {
	std::fstream inputFile(filePath);
	std::vector<std::vector<int>> data;

	if (!inputFile.is_open()) {
		std::cerr << "\033[31mError: Failed to open file!\033[0m\n";
		return data;
	}

	std::string inputLine = "";

	while (std::getline(inputFile, inputLine)) {
		std::vector<int> lineData;
		std::istringstream line(inputLine);
		int number = 0;

		while (line >> number) {
			lineData.push_back(number);
		}

		data.push_back(lineData);
	}

	inputFile.close();

	if (data.empty()) {
		std::cerr << "\033[31mError: Vector is empty!\033[0m\n";
	}
	return data;
}

void checkData(std::vector<std::vector<int>>& data) {
	int secure = 0;

	for (const auto& row : data) {
		int errorCount = countErrorsInRow(row);
		if (errorCount <= 1) {
			secure++;
		}
	}
	std::cout << secure << " report(s) are securel logged.\n";
}

int countErrorsInRow(const std::vector<int>& row) {
    if (row.size() < 2) {
        // Not enough elements to form a sequence, hence no errors.
        return 0;
    }

    int errors = 0; // Initialize error count.

    // Assess errors based on difference constraints.
    for (size_t j = 0; j < row.size() - 1; j++) {
        // Check if the difference exceeds 3.
        if (std::abs(row[j] - row[j + 1]) > 3) {
            errors++;
        }
    }

    // If the error count is more than 1, return it as too many to be secure.
    // This allows for sequences that are largely in a consistent trend with minor deviations.
    return errors;
}
