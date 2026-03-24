#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << b;

    return 0;
}