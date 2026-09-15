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

    int countOccurrences(vector<int> &arr, int target)
    {
        vector<int> ans = searchRange(arr, target);
        // Fixed: searchRange returns {-1, -1} when target not found,
        // not {n, n}, so we must check for -1 here.
        if (ans[0] == -1)
            return 0;
        return (ans[1] - ans[0]) + 1;
    }
};

void printResult(vector<int> &arr, int target)
{
    Solution sol;
    int count = sol.countOccurrences(arr, target);
    cout << "Array: [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    cout << "], target = " << target
         << " -> countOccurrences = " << count << endl;
}

int main()
{
    // Test case 1: target present multiple times
    vector<int> arr1 = {1, 2, 2, 2, 3, 4, 5};
    printResult(arr1, 2); // expected 3

    // Test case 2: target present once
    vector<int> arr2 = {5, 7, 7, 8, 8, 10};
    printResult(arr2, 5); // expected 1

    // Test case 3: target not present
    vector<int> arr3 = {1, 3, 5, 7, 9};
    printResult(arr3, 4); // expected 0

    // Test case 4: empty array
    vector<int> arr4 = {};
    printResult(arr4, 1); // expected 0

    // Test case 5: all elements equal to target
    vector<int> arr5 = {2, 2, 2, 2, 2};
    printResult(arr5, 2); // expected 5

    // Test case 6: target at the very start/end
    vector<int> arr6 = {1, 1, 2, 3, 4, 4, 4};
    printResult(arr6, 1); // expected 2
    printResult(arr6, 4); // expected 3

    return 0;
}