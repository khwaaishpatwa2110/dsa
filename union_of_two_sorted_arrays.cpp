#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of array A: ";
    cin >> n;

    int a[100000];
    cout << "Enter elements of array A: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of array B: ";
    cin >> m;

    int b[100000];
    cout << "Enter elements of array B: ";
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    int last = -1000000001; // something smaller than min constraint

    cout << "Output: ";

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            if(a[i] != last) {
                cout << a[i] << " ";
                last = a[i];
            }
            i++;
        }
        else if(a[i] > b[j]) {
            if(b[j] != last) {
                cout << b[j] << " ";
                last = b[j];
            }
            j++;
        }
        else {
            if(a[i] != last) {
                cout << a[i] << " ";
                last = a[i];
            }
            i++;
            j++;
        }
    }

    while(i < n) {
        if(a[i] != last) {
            cout << a[i] << " ";
            last = a[i];
        }
        i++;
    }

    while(j < m) {
        if(b[j] != last) {
            cout << b[j] << " ";
            last = b[j];
        }
        j++;
    }

    return 0;
}