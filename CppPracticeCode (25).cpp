#include <iostream>
#include <forward_list>

int main() {
    forward_list<int> flist = {1, 2, 3, 4, 5};

    cout << "Initial Forward List: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.push_front(0);
    cout << "After Adding Element at Front: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.pop_front();
    cout << "After Removing First Element: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    auto it = flist.begin();
    flist.insert_after(it, 10);
    cout << "After Inserting 10 After the First Element: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.remove(3);
    cout << "After Removing All Occurrences of 3: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.sort();
    cout << "Forward List After Sorting: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.reverse();
    cout << "Forward List After Reversing: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    forward_list<int> second_list = {6, 7, 8};
    flist.merge(second_list);
    flist.sort();
    cout << "After Merging with Second List and Sorting: ";
    for (int elem : flist) {
        cout << elem << " ";
    }
    cout << endl;

    flist.clear();
    cout << "Forward List Cleared: The forward list is now empty." << endl;

    return 0;
}
