#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Patient {
    string name;
    int severity;

    Patient(const string& n, int s) : name(n), severity(s) {}
};

struct CompareSeverity {
    bool operator()(const Patient& a, const Patient& b) {
        return a.severity < b.severity;
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, CompareSeverity> emergencyRoom;

    emergencyRoom.push(Patient("Alice", 5));
    emergencyRoom.push(Patient("Bob", 8));
    emergencyRoom.push(Patient("Charlie", 2));
    emergencyRoom.push(Patient("Diana", 10));

    cout << "Patients added to the queue." << endl;

    while (!emergencyRoom.empty()) {
        Patient current = emergencyRoom.top();
        emergencyRoom.pop();

        cout << "Treating patient: " << current.name << " (Severity: " << current.severity << ")" << endl;

        if (!emergencyRoom.empty()) {
            cout << "Remaining Queue: ";
            priority_queue<Patient, vector<Patient>, CompareSeverity> tempQueue = emergencyRoom;
            while (!tempQueue.empty()) {
                Patient temp = tempQueue.top();
                tempQueue.pop();
                cout << temp.name << " (Severity: " << temp.severity << ")";
                if (!tempQueue.empty()) {
                    cout << ", ";
                }
            }
            cout << endl;
        } else {
            cout << "Remaining Queue: (empty)" << endl;
        }
    }

    cout << "All patients have been treated!" << endl;

    return 0;
}
