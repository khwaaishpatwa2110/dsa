#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int freq[n];
    for(int i = 0; i < n; i++)
        freq[i] = -1;

    for(int i = 0; i < n; i++) {
        if(freq[i] != -1) continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        freq[i] = count;
    }

    cout << "Output: [";
    bool first = true;

    for(int i = 0; i < n; i++) {
        if(freq[i] != 0) {
            if(!first) cout << ", ";
            cout << "[" << arr[i] << ", " << freq[i] << "]";
            first = false;
        }
    }

    cout << "]";

    return 0;
}