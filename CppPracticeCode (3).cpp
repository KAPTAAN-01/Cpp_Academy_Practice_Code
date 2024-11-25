#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void drawCircle() {
        for (int i = -radius; i <= radius; ++i) {
            for (int j = -radius; j <= radius; ++j) {
                if (std::sqrt(i * i + j * j) <= radius) {
                    std::cout << "* ";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << "\n";
        }
};

int main() {
    double circleRadius;
    }

    std::cout << "Enter the radius of the circle: ";
    std::cin >> circleRadius;

    Circle myCircle(circleRadius);
    myCircle.drawCircle();

    return 0;
}
