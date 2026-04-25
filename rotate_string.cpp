#include <iostream>
using namespace std;

int main() {
    string s, goal;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter goal string: ";
    cin >> goal;

    int n = s.length();

    if (n != goal.length()) {
        cout << "false";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s == goal) {
            cout << "true";
            return 0;
        }

        // shift operation
        char first = s[0];
        for (int j = 0; j < n - 1; j++) {
            s[j] = s[j + 1];
        }
        s[n - 1] = first;
    }

    cout << "false";
    return 0;
}