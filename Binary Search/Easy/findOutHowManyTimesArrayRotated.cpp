#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, ans = INT_MAX, index = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // if search space is having sorted order
            if (nums[low] <= nums[high])
            {
                if (nums[low] <= ans)
                {
                    index = low;
                    ans = nums[low];
                }
                break;
            }

            // if left space is sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= ans)
                {
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            // else right space is sorted
            else
            {
                if (nums[mid] <= ans)
                {
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return index;
    }
};

void runTest(vector<int> nums, int expected)
{
    Solution sol;
    vector<int> copyNums = nums; // preserve original for printing
    int result = sol.findKRotation(copyNums);

    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "] -> Rotations: " << result
         << " (expected: " << expected << ") "
         << (result == expected ? "PASS" : "FAIL") << endl;
}

int main()
{
    runTest({4, 5, 6, 7, 0, 1, 2}, 4);
    runTest({1, 2, 3, 4, 5}, 0); // not rotated at all
    runTest({2, 1}, 1);          // rotated once
    runTest({1}, 0);             // single element
    runTest({3, 4, 5, 1, 2}, 3);
    runTest({7, 9, 11, 12, 5}, 4);

    return 0;
}