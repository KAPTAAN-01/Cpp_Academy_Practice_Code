#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> customerQueue;
    customerQueue.push("Alice");
    customerQueue.push("Bob");
    customerQueue.push("Charlie");
    customerQueue.push("Diana");

    while (!customerQueue.empty()) {
        cout << "Serving: " << customerQueue.front() << endl;
        customerQueue.pop();
        if (!customerQueue.empty()) {
            cout << "Remaining Queue: ";
            queue<string> tempQueue = customerQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front();
                tempQueue.pop();
                if (!tempQueue.empty()) cout << ", ";
            }
            cout << endl;
        }
    }
    cout << "All customers have been served!" << endl;

    return 0;
}
