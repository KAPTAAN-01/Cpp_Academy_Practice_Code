#include <iostream>
#include <vector>

// Function to compute the transpose of a matrix
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    // Get the number of rows and columns in the original matrix
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Initialize a new matrix with swapped rows and columns
    std::vector<std::vector<int>> transpose(cols, std::vector<int>(rows, 0));

    // Compute the transpose
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Get the dimensions of the matrix from the user
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Get the matrix elements from the user
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    std::cout << "Enter the matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Compute and display the transpose of the matrix
    std::vector<std::vector<int>> transpose = transposeMatrix(matrix);
    std::cout << "Original Matrix:" << std::endl;
    displayMatrix(matrix);
    std::cout << "Transpose Matrix:" << std::endl;
    displayMatrix(transpose);

    return 0;
}

