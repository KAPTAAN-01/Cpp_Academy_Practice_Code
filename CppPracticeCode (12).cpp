#include <iostream>
using namespace std;

void drawSquare(char ch, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void drawParallelogram(char ch, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < size; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void drawTriangle(char ch, int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void drawPyramid(char ch, int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = size - i; j > 0; j--) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << ch;
        }
        cout << endl;
    }
}

void drawDiamond(char ch, int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = size - i; j > 0; j--) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << ch;
        }
        cout << endl;
    }
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < size - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << ch;
        }
        cout << endl;
    }
}

void drawCylinder(char ch, int radius, int height) {
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < 2 * radius; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 2 * radius; j++) {
            if (j == 0 || j == 2 * radius - 1)
                cout << ch << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < 2 * radius; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    char choice, ch;
    int size, radius, height;

    cout << "Choose a shape to draw (s: square, p: parallelogram, t: triangle, c: cylinder, y: pyramid, d: diamond): ";
    cin >> choice;
    cout << "Enter the character to use: ";
    cin >> ch;

    if (choice == 's') {
        cout << "Enter the size of the square: ";
        cin >> size;
        drawSquare(ch, size);
    } else if (choice == 'p') {
        cout << "Enter the size of the parallelogram: ";
        cin >> size;
        drawParallelogram(ch, size);
    } else if (choice == 't') {
        cout << "Enter the size of the triangle: ";
        cin >> size;
        drawTriangle(ch, size);
    } else if (choice == 'y') {
        cout << "Enter the size of the pyramid: ";
        cin >> size;
        drawPyramid(ch, size);
    } else if (choice == 'd') {
        cout << "Enter the size of the diamond: ";
        cin >> size;
        drawDiamond(ch, size);
    } else if (choice == 'c') {
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> height;
        drawCylinder(ch, radius, height);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
