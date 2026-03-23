#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int n) {
    if (n == 0) return 0;

    int k = 1; 

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums, n);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}