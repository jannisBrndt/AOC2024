#pragma once

#include <string>
#include <vector>

// function to read in data into a vector of vectors
std::vector<std::vector<int>> readData(const std::string& filePath);

// function to determine whether a row is correct or not
void checkData(std::vector<std::vector<int>>& data);

// function to count occurences of unsave data
int countErrorsInRow(const std::vector<int>& row);
