#include <iostream>
using namespace std;

string reverseWords(string s) {
    string result = "";
    int i = s.length() - 1;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;

        if (i < 0) break;

        int j = i;

        while (i >= 0 && s[i] != ' ') i--;

        if (result.length() > 0) result += " ";

        for (int k = i + 1; k <= j; k++) {
            result += s[k];
        }
    }

    return result;
}

int main() {
    string s;

    cout << "Enter sentence: ";
    getline(cin, s);

    string result = reverseWords(s);
    cout << "Output: " << result;

    return 0;
}