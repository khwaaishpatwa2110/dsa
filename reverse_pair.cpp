#include <iostream>
using namespace std;

int mergeSort(int a[], int l, int r) {
    if (l >= r) return 0;

    int m = (l + r) / 2;
    int count = mergeSort(a, l, m) + mergeSort(a, m + 1, r);

    int j = m + 1;
    for (int i = l; i <= m; i++) {
        while (j <= r && a[i] > 2LL * a[j]) j++;
        count += j - (m + 1);
    }

    int temp[50000], i = l, k = 0;
    j = m + 1;

    while (i <= m && j <= r)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int x = 0; x < k; x++) a[l + x] = temp[x];

    return count;
}

int main() {
    int n, a[50000];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = mergeSort(a, 0, n - 1);

    cout << "Reverse pairs = " << result;

    return 0;
}