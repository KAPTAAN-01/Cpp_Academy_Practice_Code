#include <iostream>
using namespace std;

int main() {
    int start, end;
    int j,i;
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;
    cout << "Prime numbers between " << start << " and " << end << " are: " << endl;
    for (i=start; i<=end; i++) {
        if (i > 1) {  
            for (j=2; j<=i/2; j++) {
                if (i % j == 0) {
                    break; 
                }
            }
            if (j > i / 2)  
                cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
