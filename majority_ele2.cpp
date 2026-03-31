#include <iostream>
using namespace std;

int main() 
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int num[n];

    cout << "Enter elements of array:\n";
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int can1 = 0, can2 = 1;
    int count1 = 0, count2 = 0;

    for(int i = 0; i < n; i++) {
        if(num[i] == can1) 
        {
            count1++;
        }
        else if(num[i] == can2) 
        {
            count2++;
        }
        else if(count1 == 0) 
        {
            can1 = num[i];
            count1 = 1;
        }
        else if(count2 == 0) 
        {
            can2 = num[i];
            count2 = 1;
        }
        else 
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for(int i = 0; i < n; i++) 
    {
        if(num[i] == can1) count1++;
        else if(num[i] == can2) count2++;
    }

    cout << "Elements appearing more than n/3 times are: ";

    if(count1 > n/3) cout << can1 << " ";
    if(count2 > n/3) cout << can2 << " ";

    if(count1 <= n/3 && count2 <= n/3)
        cout << "None";

    return 0;
}