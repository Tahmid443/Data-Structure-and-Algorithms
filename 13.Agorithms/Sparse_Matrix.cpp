#include <iostream>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    int matrix[row][col];

    int zeroCount = 0;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];

            if (matrix[i][j] == 0)
                zeroCount++;
        }
    }

    if (zeroCount > (row * col) / 2)
    {
        cout << "\nThe matrix is a Sparse Matrix.\n";

        cout << "\nTriplet Representation:\n";
        cout << "Row Col Value\n";

        int nonZero = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] != 0)
                    nonZero++;
            }
        }

        cout << row << " " << col << " " << nonZero << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] != 0)
                {
                    cout << i << " "
                         << j << " "
                         << matrix[i][j] << endl;
                }
            }
        }
    }
    else
    {
        cout << "\nThe matrix is NOT a Sparse Matrix." << endl;
    }

    return 0;
}