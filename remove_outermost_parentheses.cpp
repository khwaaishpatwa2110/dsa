#include <iostream>
using namespace std;

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = "";
    int open = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            if (open > 0) {
                result += s[i];
            }
            open++;
        } else { // ')'
            open--;
            if (open > 0) {
                result += s[i];
            }
        }
    }

    cout << "Output: " << result;

    return 0;
}