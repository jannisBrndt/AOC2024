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
	} 
	
	std::sort(leftSide.begin(), leftSide.end());
	std::sort(rightSide.begin(), rightSide.end());
	
	
	if (leftSide.size() != rightSide.size()) {
		std::cout << "\033[31m[DEBUG] Left and right side are not equal!\033[0m\n";
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
		std::cout << "\033[32mThe absolute distance amounts to " << totalDistance << "\033[0m\n";
	}
	
	//count the frequency of element i of leftSide in rightSide
	std::vector<int> frequencies;
	int frequency = 0;
	for (int i = 0; i < leftSide.size(); i++) {
		frequency = std::count(rightSide.begin(), rightSide.end(), leftSide[i]);
		frequencies.push_back(frequency);
	}

	if (leftSide.size() != frequencies.size()) {
		std::cerr << "\033[31m[DEBUG] Error frequencies size does not match left side!\033[0m\n";
	}

	std::vector<int> similarities;
	int similarity = 0;
	for (int i = 0; i < leftSide.size(); i++) {
		similarity = leftSide[i] * frequencies[i];
		similarities.push_back(similarity);
	}

	int totalSimilarity = 0;
	for (int i = 0; i < leftSide.size(); i++) {
		totalSimilarity += similarities[i];
	}

	std::cout << "\033[32mThe total similarity amounts to " << totalSimilarity << "\033[0m\n";

	return 0;
}
