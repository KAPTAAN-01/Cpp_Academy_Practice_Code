#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Initial Vector: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    for (int i = 11; i <= 15; i++) {
        vec.push_back(i);
    }
    cout << "After Adding Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.insert(vec.begin() + 2, 50);
    cout << "After Inserting 50: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.erase(vec.begin() + 4);
    cout << "After Removing Element at Index 4: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    auto it = find(vec.begin(), vec.end(), 50);
    if (it != vec.end()) {
        cout << "Position of 50: " << distance(vec.begin(), it) << endl;
    }

    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Sorted Vector (Descending): ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "First Element: " << vec.front() << endl;
    cout << "Last Element: " << vec.back() << endl;

    vec.resize(8);
    cout << "After Resizing to 8 Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Using Iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
