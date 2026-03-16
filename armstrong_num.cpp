#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter a 3 digit number: ";
    cin >> n;

    int num = n;
    int sum = 0;

    while(n > 0) {
        int digit = n % 10;
        sum = sum + digit * digit * digit;
        n = n / 10;
    }

    if(sum == num)
        cout << num << " is armstrong number";
    else
        cout << num << " is not armstrong number";

    return 0;
}