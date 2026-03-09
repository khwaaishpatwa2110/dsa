#include <iostream>
using namespace std;

int main()
{
    int n, arr[100], largest;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    largest = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "Largest element is: " << largest;

    return 0;
}