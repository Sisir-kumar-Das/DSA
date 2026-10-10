#include <iostream>
#include <vector>
using namespace std;
//

class Solution
{
public:
    int lowerBound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int cnt_max = 0;
        int index = -1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            int cnt_ones = m - lowerBound(mat[i], m, 1);

            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main()
{
    Solution sol;

    // Test 1: expected 2 (row 2 has three 1s)
    vector<vector<int>> t1 = {
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1}};

    // Test 2: expected -1 (no 1s anywhere)
    vector<vector<int>> t2 = {
        {0, 0},
        {0, 0}};

    // Test 3: expected 1 (row 1 has two 1s)
    vector<vector<int>> t3 = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}};

    // Test 4: expected 0 (tie, first row wins)
    vector<vector<int>> t4 = {
        {0, 1},
        {0, 1}};

    cout << "Test 1: " << sol.rowWithMax1s(t1) << " (expected 2)\n";
    cout << "Test 2: " << sol.rowWithMax1s(t2) << " (expected -1)\n";
    cout << "Test 3: " << sol.rowWithMax1s(t3) << " (expected 1)\n";
    cout << "Test 4: " << sol.rowWithMax1s(t4) << " (expected 0)\n";

    return 0;
}