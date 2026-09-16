#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low += 1;
                high -= 1;
                continue;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    // Example test cases
    vector<vector<int>> testArrays = {
        {2, 5, 6, 0, 0, 1, 2},
        {2, 5, 6, 0, 0, 1, 2},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 2, 1, 1},
        {}};
    vector<int> targets = {0, 3, 0, 2, 5};

    Solution sol;
    for (int i = 0; i < (int)testArrays.size(); i++)
    {
        bool result = sol.search(testArrays[i], targets[i]);
        cout << "Test " << i + 1 << ": target = " << targets[i]
             << " -> " << (result ? "true" : "false") << endl;
    }

    return 0;
}