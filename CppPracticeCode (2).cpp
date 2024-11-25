#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
public:
    void performOperations(int numValues) {
    
        for (int i = 0; i < numValues; ++i) {
            double value;
            cout << "Enter value #" << i + 1 << ": ";
            cin >> value;
        
            
			
	cout << "Select operation:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Power\n";
            cout << "6. Square Root\n";
            cout << "7. Cosine\n";
            cout << "8. Sine\n";
            cout << "9. Tangent\n";
            cout << "Enter operation number: ";
       

            int operation;
            cin >> operation;

            switch (operation) {
                case 1:
                    result += value;
                    break;
                case 2:
                    result -= value;
                    break;
                case 3:
                    result *= value;
                    break;
                case 4:
                    if (value != 0) {
                        result /= value;
                    } else {
                        cout << "Error: Division by zero!\n";
                        return;
                    }
                    break;
                case 5:
                    result = pow(result, value);
                    break;
                case 6:
                    result = sqrt(value);
                    break;
                case 7:
                    result = cos(value);
                    break;
                case 8:
                    result = sin(value);
                    break;
                case 9:
                    result = tan(value);
                    break;
                 case 10:   
                    cout<<"Answer"<<result<<"\n";
                    break;
                default:
                    cout << "Invalid operation!\n";
                    return;
            }
        }

        cout << "Result: " << result << "\n";
    }

private:
    double result = 0.0;
};

int main() {
    int numValues;
    cout << "Enter the number of values: ";
    cin >> numValues;

    Calculator calculator;
    calculator.performOperations(numValues);

    return 0;
}
