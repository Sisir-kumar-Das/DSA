#include <iostream>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    int col0 = 1;
    // vector<int> rowZero(m, 0), colZero(n, 0);

    // mark rows/cols that contain a zero
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j != 0)
                    arr[0][j] = 0;
                else
                {
                    col0 = 0;
                }
            }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[0][j] == 0 || arr[i][0] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
            arr[0][j] = 0;
    }
    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    cout << "Enter " << m * n << " elements:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    setMatrixZero(arr);

    cout << "\nThe matrix is:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}