#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 0; row < n; row++)
    {
        vector<int> currentRow(row + 1);
        long long res = 1;
        currentRow[0] = 1;

        for (int col = 1; col <= row; col++)
        {
            // nCr formula built incrementally: res = res * (row - col + 1) / col
            res = res * (row - col + 1) / col;
            currentRow[col] = (int)res;
        }

        ans.push_back(currentRow);
    }

    return ans;
}
//

int main()
{
    int n;

    cout << "Enter the row number at which you want to find element: ";
    cin >> n;

    // pascal traingle
    vector<vector<int>> value = pascalTriangle(n);

    return 0;
}