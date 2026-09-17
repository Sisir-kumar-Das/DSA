#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // if array is already sorted
            if (nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            // if left half is sorted
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // right half is sorted
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11, 13, 15, 17},
        {2, 1},
        {1},
        {2, 3, 4, 5, 1}};

    for (auto &nums : testCases)
    {
        vector<int> copy = nums; // findMin doesn't mutate, but keeping it safe
        cout << "Array: [";
        for (int i = 0; i < (int)nums.size(); i++)
        {
            cout << nums[i] << (i + 1 < (int)nums.size() ? ", " : "");
        }
        cout << "] -> Min: " << sol.findMin(copy) << endl;
    }

    return 0;
}