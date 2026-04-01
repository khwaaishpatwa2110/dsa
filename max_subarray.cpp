#include <iostream>
using namespace std;

int maxSubArray(int nums[], int n) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int nums[n];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    int result = maxSubArray(nums, n);

    cout << "\nThe maximum subarray sum is: " << result << endl;

    return 0;
}