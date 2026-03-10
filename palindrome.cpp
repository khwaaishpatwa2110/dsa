#include<iostream>
using namespace std;

int main()
{
    int num, og, rev = 0, rem;

    cout << "Enter a number: ";
    cin >> num;

    og = num;

    while(num != 0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }

    if(og == rev)
        cout << "It is a palindrome number";
    else
        cout << "It is not a palindrome number";

    return 0;
}