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

    int j = 0; // position for non-zero

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    cout << "Output: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}