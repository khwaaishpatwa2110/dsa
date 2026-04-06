#include <iostream>
using namespace std;

struct Interval 
{
    int start, end;
};

int main() 
{
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    Interval arr[100];

    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].start >> arr[i].end;
    }

    // manual sorting (bubble sort)
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].start > arr[j + 1].start) 
            {
                Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // merge
    Interval result[100];
    int k = 0;

    result[k] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[k].end) 
        {
            // merge
            if (arr[i].end > result[k].end)
                result[k].end = arr[i].end;
        } else 
        {
            k++;
            result[k] = arr[i];
        }
    }

    // output
    cout << "Merged intervals:\n";
    for (int i = 0; i <= k; i++) 
    {
        cout << "[" << result[i].start << ", " << result[i].end << "] ";
    }

    return 0;
}