#include<iostream>
using namespace std;

int main() {
    int b, x, n, m;
    int sum = 0;

    cout << "Enter the maximum number for counting: "<<endl;
    cin >> m;

    // Counting loop
    for (int i = 0; i <= m; i++) {
        cout << i << endl;
    }

    cout << "HOW MANY DIGITS YOU WANT TO ADD: "<<endl;
    cin >> n;

    // Addition of n digits
    for (b = 0; b <= m - n + 1; b++) {
        sum = 0;
        for (x = 0; x < n; x++) {
            sum += b + x;
        }
        cout << "Sum of " << n << " numbers starting from " << b << " = " << sum << endl;
    }

    return 0;
}
