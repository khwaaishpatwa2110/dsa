#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter number of elements in nums1 (m): ";
    cin >> m;

    cout << "Enter number of elements in nums2 (n): ";
    cin >> n;

    int nums1[m + n], nums2[n];

    cout << "Enter elements of nums1 (only " << m << " elements): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    // fill remaining with 0
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // if nums2 still has elements
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}