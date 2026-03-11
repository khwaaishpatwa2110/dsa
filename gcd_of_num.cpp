#include<iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD is: " << a;

    return 0;
}