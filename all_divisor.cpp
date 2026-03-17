#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int large[100000]; 
    int k = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                large[k++] = n / i;
            }
        }
    }

    for (int i = k - 1; i >= 0; i--) {
        cout << large[i] << " ";
    }

    return 0;
}