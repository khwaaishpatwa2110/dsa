#include <iostream>
#include <string>
using namespace std;

string longestCommonPrefix(string strs[], int n) {
    if (n == 0) return "";

    string prefix = strs[0];

    for (int i = 1; i < n; i++) {
        int j = 0;

        // compare characters
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }

        // cut prefix
        prefix = prefix.substr(0, j);

        // if empty, no need to continue
        if (prefix == "") {
            return "";
        }
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string strs[200]; // max size based on constraint

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs, n);
    cout << "Longest Common Prefix: " << result;

    return 0;
}