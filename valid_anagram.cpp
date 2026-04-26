#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    // if lengths are not equal -> not anagram
    if (s.length() != t.length()) {
        cout << "Result: Not an anagram";
        return 0;
    }

    int count[26] = {0};

    // count characters of first string
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    // subtract characters of second string
    for (int i = 0; i < t.length(); i++) {
        count[t[i] - 'a']--;
    }

    // check if all values are 0
    int flag = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "Result: Strings are anagrams";
    else
        cout << "Result: Strings are NOT anagrams";

    return 0;
}