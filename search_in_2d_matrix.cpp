#include <iostream>
using namespace std;

int searchMatrix(int matrix[100][100], int m, int n, int target) {
    int low = 0;
    int high = m * n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return 1;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int matrix[100][100];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int result = searchMatrix(matrix, m, n, target);

    if (result == 1)
        cout << "Output: true";
    else
        cout << "Output: false";

    return 0;
}