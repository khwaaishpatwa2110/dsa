#include <iostream>
using namespace std;

int main() {
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    int arr[30][30];  

    // pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;

        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    // equilateral triangle shape
    for (int i = 0; i < numRows; i++) {

        // spaces
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << "  ";
        }

        // numbers
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << "   ";
        }

        cout << endl;
    }

    return 0;
}

/*

==== WITH VECTOR ====

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle;

    // pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1);

        row[0] = 1;
        row[i] = 1;

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    // equilateral triangle shape
    for (int i = 0; i < numRows; i++) {

        // spaces for alignment
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << "  ";
        }

        // print values
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << "   ";
        }

        cout << endl;
    }

    return 0;
}

*/