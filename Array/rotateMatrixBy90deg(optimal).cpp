#include <bits/stdc++.h>
using namespace std;

void reverseMatricBy90(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    // transposing the matrix
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reversing each row for rotating matrix 90 degree
    for (int i = 0; i < m; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
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

    reverseMatricBy90(arr);

    cout << "\nThe matrix is:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}