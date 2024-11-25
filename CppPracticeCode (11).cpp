#include <iostream>
using namespace std;

void inputArray(int* arr, int size) {
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++)
        cin >> *(arr + i);
}

void displayArray(int* arr, int size) {
    cout << "Array elements are:" << endl;
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int findMax(int* arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    inputArray(arr, size);
    displayArray(arr, size);

    cout << "Maximum element in the array: " << findMax(arr, size) << endl;

    reverseArray(arr, size);
    cout << "Array after reversal:" << endl;
    displayArray(arr, size);

    delete[] arr;

    return 0;
}
