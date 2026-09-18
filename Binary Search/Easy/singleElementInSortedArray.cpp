#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // left half check and eliminate left half
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                low = mid + 1;
            // right half check and eliminate right half
            else
                high = mid - 1;
        }
        return -1;
    }
};

void runTest(vector<int> nums, int expected)
{
    Solution sol;
    vector<int> copyNums = nums; // preserve original for printing
    int result = sol.singleNonDuplicate(copyNums);

    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "] -> Single element: " << result
         << " (expected: " << expected << ") "
         << (result == expected ? "PASS" : "FAIL") << endl;
}

int main()
{
    runTest({1, 1, 2, 3, 3, 4, 4, 8, 8}, 2);
    runTest({3, 3, 7, 7, 10, 11, 11}, 10);
    runTest({1}, 1);                         // single element
    runTest({1, 1, 2}, 2);                   // unique at end
    runTest({2, 1, 1}, 2);                   // unique at start
    runTest({1, 1, 2, 2, 3, 3, 4, 5, 5}, 4); // unique towards end
    runTest({1, 1, 2, 2, 3, 4, 4}, 3);       // unique in middle-ish
    runTest({5, 5, 6, 6, 7}, 7);             // unique at very end

    return 0;
}