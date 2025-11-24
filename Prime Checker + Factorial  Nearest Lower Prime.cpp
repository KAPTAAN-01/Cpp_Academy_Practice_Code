#include <iostream>
using namespace std;

// -------- PRIME CHECKER FUNCTION --------
bool isPrime(int n) {
    if (n < 2) return false;                         // 1 prime nahi hota

    for (int i = 2; i * i <= n; i++) {               // 2 se sqrt(n) tak check
        if (n % i == 0)                              // Agar divisible ho to prime nahi
            return false;
    }
    return true;                                     // Warna prime hai
}

// -------- FACTORIAL FUNCTION --------
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++)                     // 2 se n tak multiply
        fact *= i;

    return fact;
}

// -------- FIND NEAREST LOWER PRIME --------
int lowerPrime(int n) {
    for (int i = n - 1; i >= 2; i--) {               // n se chota prime find karo
        if (isPrime(i))
            return i;
    }
    return -1;                                       // No lower prime
}

int main() {
    int number;
    cout << "Enter number: ";
    cin >> number;

    if (isPrime(number)) {                           // Check prime or not
        cout << number << " is a prime number.\n";
        cout << "Factorial = " << factorial(number); // Agar prime → factorial print kare
    }
    else {
        cout << number << " is NOT a prime number.\n";

        int lower = lowerPrime(number);              // Nearest lower prime
        cout << "Nearest lower prime: " << lower;
    }

    return 0;
}
