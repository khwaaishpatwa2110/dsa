#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    int matrix[20][20];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    // Step 1: Transpose the matrix
    for(int i = 0; i < n; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n / 2; j++) 
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }

    cout << "Rotated Matrix:\n";
    
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}