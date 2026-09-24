#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <cmath>     // for ceil
using namespace std;

class Solution
{
private:
    int sumOfAllDivisior(vector<int> &nums, int mid)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end()), ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (sumOfAllDivisior(nums, mid) <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << result << endl;

    // Try another test case
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Smallest divisor (test 2): " << sol.smallestDivisor(nums2, threshold2) << endl;

    return 0;
}