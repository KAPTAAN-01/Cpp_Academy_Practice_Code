#include<iostream>
using namespace std;

int main() {
    cout << "WHAT TYPE OF SERIES YOU WANT TO DISPLAY?" << endl;
    cout << "PRESS H FOR HARMONIC SEQUENCE: " << endl;
    cout << "PRESS A FOR ARITHMETIC PROGRESSION: " << endl;
    cout << "PRESS G FOR GEOMETRIC PROGRESSION: " << endl;
    cout << "PRESS P FOR PRIME SERIES: " << endl;

    char choice;
    cin >> choice;

    if(choice == 'A' || choice == 'a') {
        int n, a, d;
        cout << "Enter the first term and common difference for Arithmetic Progression: ";
        cin >> a >> d;
        cout << "Enter the number of terms: ";
        cin >> n;
        for(int i = 0; i < n; i++) {
            cout << a + i * d << " ";
        }
        cout << endl;
    }
    else if(choice == 'G' || choice == 'g') {
        int n, a, r;
        cout << "Enter the first term and common ratio for Geometric Progression: ";
        cin >> a >> r;
        cout << "Enter the number of terms: ";
        cin >> n;
        int term = a; // Start with the first term
        for(int i = 0; i < n; i++) {
            cout << term << " ";
            term *= r; // Multiply the previous term by the common ratio
        }
        cout << endl;
    }
    else if(choice == 'H' || choice == 'h') {
        int n;
        cout << "Enter the number of terms for Harmonic Sequence: ";
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cout << 1.0 / i << " ";
        }
        cout << endl;
    }
    else if(choice == 'P' || choice == 'p') {
        int n, num = 2, count = 0;
        cout << "Enter the number of prime terms you want: ";
        cin >> n;
        while(count < n) {
            bool prime = true;
            for(int i = 2; i <= num / 2; i++) {
                if(num % i == 0) {
                    prime = false;
                    break;
                }
            }
            if(prime) {
                cout << num << " ";
                count++;
            }
            num++;
        }
        cout << endl;
    }
    else {
        cout << "ENTER THE LETTERS GIVEN BELOW: " << endl;
        cout << "A,G,H,P,a,g,h,p" << endl;
    }
    return 0;
}
