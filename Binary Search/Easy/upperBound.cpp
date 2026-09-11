#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &nums, int x)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {

            int mid = (low + high) / 2;
            if (nums[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 2, 3, 5, 7, 9};

    // Test a few values of x
    vector<int> testValues = {0, 2, 4, 5, 10};

    for (int x : testValues)
    {
        int idx = sol.upperBound(nums, x);
        cout << "upperBound(nums, " << x << ") = " << idx;
        if (idx < (int)nums.size())
            cout << "  (nums[" << idx << "] = " << nums[idx] << ")";
        else
            cout << "  (no element > " << x << ")";
        cout << endl;
    }

    return 0;
}