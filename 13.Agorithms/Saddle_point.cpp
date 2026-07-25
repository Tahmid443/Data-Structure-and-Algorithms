#include <iostream>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    int matrix[row][col];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool found = false;

    for (int i = 0; i < row; i++)
    {
        int minCol = 0;

        // Find minimum element in the row
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] < matrix[i][minCol])
                minCol = j;
        }

        // Check if it is maximum in the column
        bool saddle = true;

        for (int k = 0; k < row; k++)
        {
            if (matrix[k][minCol] > matrix[i][minCol])
            {
                saddle = false;
                break;
            }
        }

        if (saddle)
        {
            cout << "\nSaddle Point = " << matrix[i][minCol] << endl;
            cout << "Position = (" << i << ", " << minCol << ")" << endl;
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Saddle Point Found." << endl;

    return 0;
}