#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        result = result ^ nums[i];
    }

    cout << "Single element is: " << result;

    return 0;
}