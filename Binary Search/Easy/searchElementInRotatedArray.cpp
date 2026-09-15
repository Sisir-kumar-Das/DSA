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

            // left half sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // right half sorted
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

void printResult(vector<int> &arr, int target)
{
    Solution sol;
    int idx = sol.search(arr, target);
    cout << "Array: [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    cout << "], target = " << target << " -> index = " << idx << endl;
}

int main()
{
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    printResult(arr1, 0); // expected 4
    printResult(arr1, 3); // expected -1

    vector<int> arr2 = {1};
    printResult(arr2, 0); // expected -1
    printResult(arr2, 1); // expected 0

    vector<int> arr3 = {};
    printResult(arr3, 5); // expected -1

    vector<int> arr4 = {5, 1, 3};
    printResult(arr4, 5); // expected 0
    printResult(arr4, 3); // expected 2

    vector<int> arr5 = {6, 7, 1, 2, 3, 4, 5};
    printResult(arr5, 6); // expected 0
    printResult(arr5, 5); // expected 6

    return 0;
}