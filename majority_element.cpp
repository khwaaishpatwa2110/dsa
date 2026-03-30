#include <iostream>
using namespace std;

int findMajorityElement(int num[], int n) {
    int candidate = num[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (num[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = num[i];
            count = 1;
        }
    }

    return candidate;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int num[n];  

    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int result = findMajorityElement(num, n);

    cout << "The majority element in the array is: " << result << endl;

    return 0;
}