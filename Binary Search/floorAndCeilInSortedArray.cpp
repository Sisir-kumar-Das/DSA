#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> ans;

        // ---- Find floor: largest element <= x ----
        int low = 0, high = n - 1;
        int floor = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] <= x)
            {
                floor = nums[mid];
                low = mid + 1; // try to find a larger valid floor on the right
            }
            else
            {
                high = mid - 1;
            }
        }
        ans.push_back(floor);

        // ---- Find ceil: smallest element >= x ----
        low = 0, high = n - 1;
        int ceil = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= x)
            {
                ceil = nums[mid];
                high = mid - 1; // try to find a smaller valid ceil on the left
            }
            else
            {
                low = mid + 1;
            }
        }
        ans.push_back(ceil);

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3, 4, 4, 7, 8, 10};

    vector<int> testValues = {5, 4, 0, 15, 8};

    for (int x : testValues)
    {
        vector<int> result = sol.getFloorAndCeil(nums, x);
        cout << "x = " << x << " -> floor = " << result[0]
             << ", ceil = " << result[1] << endl;
    }

    return 0;
}