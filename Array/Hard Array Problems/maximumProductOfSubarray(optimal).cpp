#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int suffix = 1, prefix = 1;
        for (int i = 0; i < n; i++)
        {
            if (suffix == 0)
                suffix = 1;
            if (prefix == 0)
                prefix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {0, 2},
        {-2, -3, 7},
        {6, -3, -10, 0, 2}};

    for (auto &nums : testCases)
    {
        cout << "Input: [";
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << (i + 1 < nums.size() ? ", " : "");
        }
        cout << "] -> Max Product: " << sol.maxProduct(nums) << endl;
    }

    return 0;
}