#include <iostream>
using namespace std;

int main() {
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> x;

    // Linear search
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            index = i;
            break; 
        }
    }

    cout << "Output: " << index;

    return 0;
}