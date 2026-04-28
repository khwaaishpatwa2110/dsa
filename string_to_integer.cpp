#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();
    int sign = 1;
    long long result = 0;

    int INT_MAX_VAL = 2147483647;
    int INT_MIN_VAL = -2147483648;

    // ignore leading spaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // check sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // convert digits
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        result = result * 10 + digit;

        // handle overflow manually
        if (sign == 1 && result > INT_MAX_VAL) {
            return INT_MAX_VAL;
        }
        if (sign == -1 && -result < INT_MIN_VAL) {
            return INT_MIN_VAL;
        }

        i++;
    }

    return sign * result;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int ans = myAtoi(s);
    cout << "Output: " << ans;

    return 0;
}