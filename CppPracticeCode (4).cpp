#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error! Division by zero." << endl;
        return 0;
    }
}

double squareRoot(double a) {
    if (a < 0) {
        cout << "Error! Negative input for square root." << endl;
        return -1;
    } else {
        return sqrt(a);
    }
}

double power(double a, double b) {
    return pow(a, b);
}

double sine(double a) {
    return sin(a);
}

double cosine(double a) {
    return cos(a);
}

double tangent(double a) {
    if (cos(a) != 0) {
        return tan(a);
    } else {
        cout << "Error! Tangent is undefined for this angle." << endl;
        return 0;
    }
}

double logarithm(double a) {
    if (a <= 0) {
        cout << "Error! Logarithm undefined for non-positive numbers." << endl;
        return -1;
    } else {
        return log(a);
    }
}

double factorial(int n) {
    if (n < 0) {
        cout << "Error! Factorial of a negative number doesn't exist." << endl;
        return -1;
    }
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void displayArithmeticProgression() {
    int n, a, d;
    cout << "Enter the first term and common difference for Arithmetic Progression: ";
    cin >> a >> d;
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << a + i * d << " ";
    }
    cout << endl;
}

void displayGeometricProgression() {
    int n, a, r;
    cout << "Enter the first term and common ratio for Geometric Progression: ";
    cin >> a >> r;
    cout << "Enter the number of terms: ";
    cin >> n;
    int term = a;
    for (int i = 0; i < n; i++) {
        cout << term << " ";
        term *= r;
    }
    cout << endl;
}

void displayHarmonicSequence() {
    int n;
    cout << "Enter the number of terms for Harmonic Sequence: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << 1.0 / i << " ";
    }
    cout << endl;
}

void displayPrimeSeries() {
    int n, num = 2, count = 0;
    cout << "Enter the number of prime terms you want: ";
    cin >> n;
    while (count < n) {
        bool prime = true;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
}

void matrixEchelonForm(vector<vector<double>>& matrix, int rows, int cols) {
    int i = 0, j = 0;
    while (i < rows && j < cols) {
        if (matrix[i][j] == 0) {
            bool found = false;
            for (int k = i + 1; k < rows; k++) {
                if (matrix[k][j] != 0) {
                    swap(matrix[i], matrix[k]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                j++;
                continue;
            }
        }
        for (int k = i + 1; k < rows; k++) {
            double factor = matrix[k][j] / matrix[i][j];
            for (int l = j; l < cols; l++) {
                matrix[k][l] -= factor * matrix[i][l];
            }
        }
        i++;
        j++;
    }
    cout << "Row Echelon Form: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

vector<vector<double>> subtractMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();
    vector<vector<double>> result(rows1, vector<double>(cols2));

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible!" << endl;
        return result;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

vector<vector<double>> transposeMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<double>> transposed(cols, vector<double>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

vector<vector<double>> invertMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (augmented[i][i] == 0) {
            cout << "Matrix is singular and cannot be inverted." << endl;
            return {};
        }
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return inverse;
}

void displayMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void displayMenu() {
    cout << "\nMenu: Choose an option" << endl;
    cout << "1. Calculator" << endl;
    cout << "2. Series" << endl;
    cout << "3. Matrix Operations" << endl;
    cout << "4. Exit" << endl;
}

void displayCalculatorMenu() {
    cout << "\nCalculator Menu" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Square Root" << endl;
    cout << "6. Power" << endl;
    cout << "7. Sine" << endl;
    cout << "8. Cosine" << endl;
    cout << "9. Tangent" << endl;
}

void displaySeriesMenu() {
    cout << "Series Options:" << endl;
    cout << "A. Arithmetic Progression" << endl;
    cout << "G. Geometric Progression" << endl;
    cout << "H. Harmonic Sequence" << endl;
    cout << "P. Prime Series" << endl;
}

void displayMatrixMenu() {
    cout << "Matrix Operations:" << endl;
    cout << "1. Matrix Echelon Form" << endl;
    cout << "2. Matrix Addition" << endl;
    cout << "3. Matrix Subtraction" << endl;
    cout << "4. Matrix Multiplication" << endl;
    cout << "5. Matrix Inversion" << endl;
}

int main() {
    int mainChoice;
    while (true) {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int calcChoice;
            double num1, num2;
            while (true) {
                displayCalculatorMenu();
                cout << "Enter your choice (1-9): ";
                cin >> calcChoice;

                switch (calcChoice) {
                    case 1:
                        cout << "Enter two numbers: ";
                        cin >> num1 >> num2;
                        cout << "Result: " << add(num1, num2) << endl;
                        break;
                    case 2:
                        cout << "Enter two numbers: ";
                        cin >> num1 >> num2;
                        cout << "Result: " << subtract(num1, num2) << endl;
                        break;
                    case 3:
                        cout << "Enter two numbers: ";
                        cin >> num1 >> num2;
                        cout << "Result: " << multiply(num1, num2) << endl;
                        break;
                    case 4:
                        cout << "Enter two numbers: ";
                        cin >> num1 >> num2;
                        cout << "Result: " << divide(num1, num2) << endl;
                        break;
                    case 5:
                        cout << "Enter a number: ";
                        cin >> num1;
                        cout << "Result: " << squareRoot(num1) << endl;
                        break;
                    case 6:
                        cout << "Enter base and exponent: ";
                        cin >> num1 >> num2;
                        cout << "Result: " << power(num1, num2) << endl;
                        break;
                    case 7:
                        cout << "Enter angle in radians: ";
                        cin >> num1;
                        cout << "Result: " << sine(num1) << endl;
                        break;
                    case 8:
                        cout << "Enter angle in radians: ";
                        cin >> num1;
                        cout << "Result: " << cosine(num1) << endl;
                        break;
                    case 9:
                        cout << "Enter angle in radians: ";
                        cin >> num1;
                        cout << "Result: " << tangent(num1) << endl;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                cout << "Do you want to continue in the calculator? (1: Yes, 0: No): ";
                int continueCalc;
                cin >> continueCalc;
                if (continueCalc == 0) break;
            }
        } 
        else if (mainChoice == 2) {
            char seriesChoice;
            displaySeriesMenu();
            cout << "Enter your choice: ";
            cin >> seriesChoice;

            switch (seriesChoice) {
                case 'A':
                case 'a':
                    displayArithmeticProgression();
                    break;
                case 'G':
                case 'g':
                    displayGeometricProgression();
                    break;
                case 'H':
                case 'h':
                    displayHarmonicSequence();
                    break;
                case 'P':
                case 'p':
                    displayPrimeSeries();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } 
        else if (mainChoice == 3) {
            displayMatrixMenu();
            cout << "Enter your choice: ";
            int matrixChoice;
            cin >> matrixChoice;

            if (matrixChoice == 1) {
                int rows, cols;
                cout << "Enter the number of rows and columns of the matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix(rows, vector<double>(cols));
                cout << "Enter the elements of the matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix[i][j];
                    }
                }
                matrixEchelonForm(matrix, rows, cols);
            } 
            else if (matrixChoice == 2) {
                int rows, cols;
                cout << "Enter the number of rows and columns of the first matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix1(rows, vector<double>(cols));
                cout << "Enter the elements of the first matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix1[i][j];
                    }
                }
                cout << "Enter the number of rows and columns of the second matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix2(rows, vector<double>(cols));
                cout << "Enter the elements of the second matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix2[i][j];
                    }
                }
                vector<vector<double>> result = addMatrices(matrix1, matrix2);
                cout << "Matrix Addition Result: " << endl;
                displayMatrix(result);
            } 
            else if (matrixChoice == 3) {
                int rows, cols;
                cout << "Enter the number of rows and columns of the first matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix1(rows, vector<double>(cols));
                cout << "Enter the elements of the first matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix1[i][j];
                    }
                }
                cout << "Enter the number of rows and columns of the second matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix2(rows, vector<double>(cols));
                cout << "Enter the elements of the second matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix2[i][j];
                    }
                }
                vector<vector<double>> result = subtractMatrices(matrix1, matrix2);
                cout << "Matrix Subtraction Result: " << endl;
                displayMatrix(result);
            } 
            else if (matrixChoice == 4) {
                int rows1, cols1, rows2, cols2;
                cout << "Enter the number of rows and columns of the first matrix: ";
                cin >> rows1 >> cols1;
                vector<vector<double>> matrix1(rows1, vector<double>(cols1));
                cout << "Enter the elements of the first matrix: " << endl;
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols1; j++) {
                        cin >> matrix1[i][j];
                    }
                }
                cout << "Enter the number of rows and columns of the second matrix: ";
                cin >> rows2 >> cols2;
                vector<vector<double>> matrix2(rows2, vector<double>(cols2));
                cout << "Enter the elements of the second matrix: " << endl;
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        cin >> matrix2[i][j];
                    }
                }
                vector<vector<double>> result = multiplyMatrices(matrix1, matrix2);
                cout << "Matrix Multiplication Result: " << endl;
                displayMatrix(result);
            } 
            else if (matrixChoice == 5) {
                int rows, cols;
                cout << "Enter the number of rows and columns of the matrix: ";
                cin >> rows >> cols;
                vector<vector<double>> matrix(rows, vector<double>(cols));
                cout << "Enter the elements of the matrix: " << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cin >> matrix[i][j];
                    }
                }
                vector<vector<double>> result = invertMatrix(matrix);
                if (!result.empty()) {
                    cout << "Matrix Inverse Result: " << endl;
                    displayMatrix(result);
                }
            }
        } 
        else if (mainChoice == 4) {
            cout << "Exiting the program..." << endl;
            break;
        } 
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
