#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[100];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = n - 2;

    // step 1: find first decreasing element from right
    while(i >= 0 && a[i] >= a[i + 1]) {
        i--;
    }

    if(i >= 0) {
        int j = n - 1;

        // step 2: find element just greater than a[i]
        while(a[j] <= a[i]) {
            j--;
        }

        // swap a[i] and a[j]
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // step 3: reverse from i+1 to end
    int start = i + 1;
    int end = n - 1;

    while(start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }

    cout << "Next permutation: ";
    for(int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }

    return 0;
}