#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[3000];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Simple bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Triplets are:\n";

    for(int i = 0; i < n-2; i++) {

        // skip duplicates
        if(i > 0 && arr[i] == arr[i-1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum == 0) {
                cout << "[" << arr[i] << ", " << arr[left] << ", " << arr[right] << "]\n";

                left++;
                right--;

                // skip duplicates
                while(left < right && arr[left] == arr[left-1]) left++;
                while(left < right && arr[right] == arr[right+1]) right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return 0;
}