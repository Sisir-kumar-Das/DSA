#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraversalOfMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> spiral;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            spiral.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            spiral.push_back(arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i <= left; i--)
            {
                spiral.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i <= top; i--)
            {
                spiral.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return spiral;
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

    vector<int> spiral = spiralTraversalOfMatrix(arr);

    cout << "\nThe spiral traversal is:\n";
    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
        cout << endl;
    }

    return 0;
}