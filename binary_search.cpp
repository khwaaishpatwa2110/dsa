#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) 
{
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() 
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter target: "; // number to know the index of
    cin >> target;

    int result = binarySearch(arr, n, target);

    cout << "Output (at index position): "<< result;

    return 0;
}