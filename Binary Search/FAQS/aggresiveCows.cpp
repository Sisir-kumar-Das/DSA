#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool canWePlace(vector<int> &nums, int dist, int cows)
    {
        int n = nums.size();
        int cntCows = 1, lastCow = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - lastCow >= dist)
            {
                cntCows++;
                lastCow = nums[i];
            }
        }
        if (cntCows >= cows)
            return true;
        else
            return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(nums, mid, k) == true)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of stalls and number of cows: ";
    cin >> n >> k;

    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    Solution sol;
    cout << "Largest minimum distance: " << sol.aggressiveCows(stalls, k) << endl;
    return 0;
}