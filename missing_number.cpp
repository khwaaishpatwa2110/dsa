#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int nums[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Expected sum from 0 to n
    int total = n * (n + 1) / 2;

    // Actual sum of array
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int missing = total - sum;

    cout << "Missing number: " << missing;

    return 0;
}