#include <iostream>
using namespace std;

int main() {
    int n, i;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        cout << n << " is not a prime number";
        return 0;
    }

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            cout << n << " is not a prime number";
            return 0;
        }
    }

    cout << n << " is a prime number";

    return 0;
}