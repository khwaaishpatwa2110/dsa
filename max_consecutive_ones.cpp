#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int num[n];
    cout << "Enter elements (0 or 1): ";
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int count = 0, maxCount = 0;

    for(int i = 0; i < n; i++) {
        if(num[i] == 1) {
            count++;
            if(count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 0;
        }
    }

    cout << "Maximum consecutive 1's: " << maxCount;

    return 0;
}