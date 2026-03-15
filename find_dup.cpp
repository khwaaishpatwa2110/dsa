#include <iostream>
using namespace std;

int findDuplicate(int nums[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(nums[i] == nums[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    int nums[] = {1,3,4,2,2};
    int n = 5;

    cout << "Duplicate number: " << findDuplicate(nums, n);
}