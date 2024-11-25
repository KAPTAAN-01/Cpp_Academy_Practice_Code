#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    string input;
    cout << "Enter the expression: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
