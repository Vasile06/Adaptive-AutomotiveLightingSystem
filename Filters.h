#pragma once
#include <vector>
#include <stdexcept>
class Filters
{
public:
	// Function to compute transpose of a matrix
	std::vector<std::vector<float>> transposeMatrix(const std::vector<std::vector<float>>& matrix) {
		if (matrix.empty())
			throw std::invalid_argument("Matrix cannot be empty.");

		float rows = matrix.size();
		float cols = matrix[0].size();

		std::vector<std::vector<float>> transpose(cols, std::vector<float>(rows));

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				transpose[j][i] = matrix[i][j];
			}
		}

		return transpose;
	}

};