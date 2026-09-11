#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lowerBound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = lowerBound(nums, target);
        if (first == n || nums[first] != target)
            return {-1, -1};
        return {first, upperBound(nums, target) - 1};
    }
};

void printResult(vector<int> &nums, int target)
{
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ",";
    }
    cout << "], target = " << target;
    cout << " -> [" << result[0] << "," << result[1] << "]\n";
}

int main()
{
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    printResult(nums1, 8); // Expected: [3,4]

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    printResult(nums2, 6); // Expected: [-1,-1]

    vector<int> nums3 = {};
    printResult(nums3, 0); // Expected: [-1,-1]

    vector<int> nums4 = {1};
    printResult(nums4, 1); // Expected: [0,0]

    return 0;
}