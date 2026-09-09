#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    // Test case 1: normal sorted array
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << "Test 1 -> Index: " << sol.search(nums1, target1) << " (expected 4)\n";

    // Test case 2: target not present
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << "Test 2 -> Index: " << sol.search(nums2, target2) << " (expected -1)\n";

    // Test case 3: rotated array (this will likely FAIL / give wrong logic)
    vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
    int target3 = 0;
    cout << "Test 3 (rotated) -> Index: " << sol.search(nums3, target3)
         << " (this problem needs rotated-array binary search, not plain)\n";

    return 0;
}