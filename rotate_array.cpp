#include <iostream>
using namespace std;

void rotate(int arr[], int n, int k) {
    int temp[100000];  // assuming max size

    k = k % n;

    // copy last k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // copy remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // copy back to original array
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;
    int arr[100000];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    rotate(arr, n, k);

    cout << "Array after rotation: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}