#pragma once

#include <string>
#include <vector>

std::vector<std::vector<char>> loadFile(const std::string& filePath);

bool searchFrom(const std::vector<std::vector<char>>& grid, int x, int y, const std::string& word, int dx, int dy);

int countOccurrences(const std::vector<std::vector<char>>& grid, const std::string& word);
