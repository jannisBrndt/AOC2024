#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

int main() {

	// path has to be the one viewed fom where it is executed (in build directory).	
	std::ifstream inputFile("../assets/puzzle_input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "\033[31m[DEBUG] Failed to open file!\033[0m\n";
		return 1;
	}

	// The sides to store the values
	std::vector<int> leftSide;
	std::vector<int> rightSide;
	
	// The current values to store in the respective vector
	int left = 0;
	int right = 0;

	while (inputFile >> left >> right) {
				
		leftSide.push_back(left);
		rightSide.push_back(right);
	}
	
	inputFile.close();

	// check if vectors are empty
	if (leftSide.empty() || rightSide.empty()) {
		std::cerr << "\033[31m[DEBUG] One of the vectors is empty!\033[0m\n";
		return 1;
	} else {
		std::cout << "\033[32m[DEBUG]Sorting...\033[0m\n";
		std::sort(leftSide.begin(), leftSide.end());
		std::sort(rightSide.begin(), rightSide.end());
	}
	
	if (leftSide.size() != rightSide.size()) {
		std::cout << "\033[31m[DEBUG] Left and right side are not equal!\033[0m\n";
	} else {
		std::cout << "\033[32m[DEBUG] Left and right side are equal!\033[0m\n";
	}

	// calculate the distance of each row
	std::vector<int> distances;
	int distance = 0;
	for (int i = 0; i < leftSide.size(); i++) {
		distance = abs(leftSide[i] - rightSide[i]);
		distances.push_back(distance);
	}

	// calculate the total distance
	int totalDistance = 0;
	for (int i = 0; i < distances.size(); i++) {
		totalDistance += distances[i];
	}
	
	if (distances.empty()) {
		std::cerr << "\033[31mNo distances available to calculate average!\n";
		return 1;
	} else {
		int averageDistance = totalDistance / distances.size();
		std::cout << "\033[32mThe absolute distance amounts to " << averageDistance << "\033[0m\n";
	}


	return 0;
}
