#include "../include/utility.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<char>> loadFile(const std::string& filePath) {
	
	std::fstream file(filePath);
	std::vector<std::vector<char>> grid;
	std::string line;

	if (!file.is_open()) {
		std::cerr << "\033[31mError: File could not be loaded!\033[0m\n";
		return grid;
	}

	while(getline(file, line)) {
		std::vector<char> row;
		for (char c : line) {
			row.push_back(c);
		}
		grid.push_back(row);
	}
	return grid;
}

bool searchFrom(const std::vector<std::vector<char>>& grid, int x, int y, const std::string& word, int dx, int dy) {
	int n = grid.size();
	int m = grid[0].size();
	int len = word.length();

	int end_x = x + dx * (len - 1);
	int end_y = y + dy * (len - 1);
	if (end_x < 0 || end_x >= n || end_y < 0 || end_y >= m) {
		return false;
	}

	for (int i = 0; i < len; ++ i) {
		if (grid[x + i * dx][y + i * dy] != word[i]) {
			return false;
		}
	}
	return true;
}

int countOccurrences(const std::vector<std::vector<char>>& grid, const std::string& word) {
	int count = 0;
	int n = grid.size();
	int m = grid[0].size();

	std::vector<std::pair<int, int>> directions = {
	{0, 1}, {1, 0}, {1, 1}, {-1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}
	};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (auto& dir : directions) {
				if (searchFrom(grid, i, j, word, dir.first, dir.second)) {
					count++;
				}
			}
		}
	}

	return count;
}
