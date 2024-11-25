#include <iostream>
#include <deque>

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};

    for (int elem : dq) cout << elem << " ";
    cout << endl;

    dq.push_front(5);
    dq.push_back(60);
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    auto it = dq.begin() + 2;
    dq.insert(it, 25);
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    it = dq.begin() + 3;
    dq.erase(it);
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    for (size_t i = 0; i < dq.size() - 1; ++i) {
        for (size_t j = i + 1; j < dq.size(); ++j) {
            if (dq[i] > dq[j]) {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    while (dq.size() > 4) dq.pop_back();
    for (int elem : dq) cout << elem << " ";
    cout << endl;

    for (auto it = dq.begin(); it != dq.end(); ++it) cout << *it << " ";
    cout << endl;

    return 0;
}
