#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return searchHelper(nums, target, 0, nums.size() - 1);
    }

private:
    int searchHelper(vector<int> &nums, int target, int low, int high)
    {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half [low..mid] is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                return searchHelper(nums, target, low, mid - 1);
            else
                return searchHelper(nums, target, mid + 1, high);
        }
        // Right half [mid..high] is sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
                return searchHelper(nums, target, mid + 1, high);
            else
                return searchHelper(nums, target, low, mid - 1);
        }
    }
};

int main()
{
    Solution sol;

    // Test 1: rotated array, target present
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test 1 -> Index: " << sol.search(nums1, target1) << " (expected 4)\n";

    // Test 2: rotated array, target not present
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test 2 -> Index: " << sol.search(nums2, target2) << " (expected -1)\n";

    // Test 3: no rotation (fully sorted)
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 3;
    cout << "Test 3 -> Index: " << sol.search(nums3, target3) << " (expected 2)\n";

    // Test 4: single element, present
    vector<int> nums4 = {5};
    int target4 = 5;
    cout << "Test 4 -> Index: " << sol.search(nums4, target4) << " (expected 0)\n";

    // Test 5: single element, absent
    vector<int> nums5 = {5};
    int target5 = -5;
    cout << "Test 5 -> Index: " << sol.search(nums5, target5) << " (expected -1)\n";

    // Test 6: rotation point at target
    vector<int> nums6 = {6, 7, 0, 1, 2, 4, 5};
    int target6 = 6;
    cout << "Test 6 -> Index: " << sol.search(nums6, target6) << " (expected 0)\n";

    return 0;
}