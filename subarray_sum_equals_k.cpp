#include <iostream>
using namespace std;

int main()
{
    int n, k;
    
    cout << "Enter size: ";
    cin >> n;
    
    int nums[20000];  // constraint limit
    
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    cout << "Enter k: ";
    cin >> k;
    
    int count = 0;

    // check all subarrays
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        
        for(int j = i; j < n; j++)
        {
            sum = sum + nums[j];
            
            if(sum == k)
            {
                count++;
            }
        }
    }

    cout << "Total subarrays: " << count;

    return 0;
}