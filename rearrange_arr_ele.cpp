#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter size of array (even no.) : ";
    cin >> n;

    int a[n];

    cout << "Enter elements (equal positive and negative): \n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result[n];
    int posIndex = 0;   // even index
    int negIndex = 1;   // odd index

    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            result[posIndex] = a[i];
            posIndex += 2;
        }
        else
        {
            result[negIndex] = a[i];
            negIndex += 2;
        }
    }

    cout << "\nRearranged array:\n";
    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}