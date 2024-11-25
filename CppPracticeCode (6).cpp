#include <iostream>
#include <vector>

using namespace std;

class DecimalConverter {
public:
    DecimalConverter(int decimalNumber) : decimalNumber(decimalNumber) {}

    void convertToHexadecimal() {
        int temp = decimalNumber;
        while (temp > 0) {
            int remainder = temp % 16;
            hexadecimal.push_back(getHexDigit(remainder));
            temp /= 16;
        }

        displayResult("Hexadecimal");
    }

    void convertToBinary() {
        int temp = decimalNumber;
        while (temp > 0) {
            binary.push_back(temp % 2);
            temp /= 2;
        }

        displayResult("Binary");
    }

private:
    int decimalNumber;
    vector<char> hexadecimal;
    vector<int> binary;

    char getHexDigit(int value) {
        if (value >= 0 && value <= 9) {
            return static_cast<char>('0' + value);
        } else {
            return static_cast<char>('A' + value - 10);
        }
    }

    void displayResult(const string& system) {
        cout << decimalNumber << " in " << system << " is: ";

        if (system == "Hexadecimal") {
            for (auto it = hexadecimal.rbegin(); it != hexadecimal.rend(); ++it) {
                cout << *it;
            }
        } else if (system == "Binary") {
            for (auto it = binary.rbegin(); it != binary.rend(); ++it) {
                cout << *it;
            }
        }

        cout << endl;
    }
};

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    DecimalConverter converter(decimalNumber);
    converter.convertToHexadecimal();
    converter.convertToBinary();

    return 0;
}
