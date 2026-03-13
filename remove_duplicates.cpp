#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int n)
{
    if (n == 0) return 0;

    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main()
{
    int nums[] = {10,11,12,12,33,44,54,65};
    int n = 8;

    int k = removeDuplicates(nums, n);

    cout << "Unique elements: ";
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << "\nTotal unique = " << k;
}