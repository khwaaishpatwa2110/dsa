#include <iostream>
using namespace std;

int main() {
    string s, t;

    cout << "Enter 1st string: ";
    cin >> s;

    cout << "Enter 2nd string: ";
    cin >> t;

    if (s.length() != t.length()) {
        cout << "Result: Not Isomorphic";
        return 0;
    }

    char map1[256] = {0};
    char map2[256] = {0};

    int flag = 1;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (map1[c1] == 0 && map2[c2] == 0) {
            map1[c1] = c2;
            map2[c2] = c1;
        }
        else {
            if (map1[c1] != c2 || map2[c2] != c1) {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        cout << "Result: Isomorphic";
    else
        cout << "Result: Not Isomorphic";

    return 0;
}