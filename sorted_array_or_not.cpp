#include <iostream>
using namespace std;

int check(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[(i+1) % n]) {
            count++;
        }
    }

    if(count <= 1)
        return true;
    else
        return false;
}

int main() {
    int arr[] = {3,4,5,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(check(arr, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}