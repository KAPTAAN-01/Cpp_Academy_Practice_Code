#include <iostream>
#include <fstream>
#include <cmath>

class TrigonometryCalculator {
public:
    TrigonometryCalculator() {}

    double calculateSine(double angle) {
        return sin(degToRad(angle));
    }

    double calculateCosine(double angle) {
        return cos(degToRad(angle));
    }

private:
    double degToRad(double degrees) {
        return degrees * M_PI / 180.0;
    }
};

int main() {
    std::ofstream outputFile("trigonometry_values.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    TrigonometryCalculator calculator;

    outputFile << "Angle,Degree,Sine,Cosine" << std::endl;

    for (int angle = 0; angle <= 360; angle++) {
        double sineValue = calculator.calculateSine(angle);
        double cosineValue = calculator.calculateCosine(angle);

        outputFile << angle << "," << sineValue << "," << cosineValue << std::endl;
    }

    outputFile.close();

    std::cout << "Trigonometry values have been calculated and saved to 'trigonometry_values.csv'." << std::endl;

    return 0;
}
