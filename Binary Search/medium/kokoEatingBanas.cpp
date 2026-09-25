#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <cmath>     // for ceil
using namespace std;

class Solution
{
private:
    long long sumOfEatingOfPiles(vector<int> &piles, int mid)
    {
        int n = piles.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)piles[i] / (double)mid);
        }
        return sum;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sumOfEatingOfPiles(piles, mid) <= h)
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

    // Your failing test case — should now correctly output 3
    vector<int> piles1 = {805306368, 805306368, 805306368};
    int h1 = 1000000000;
    cout << "Test 1 (expected 3): " << sol.minEatingSpeed(piles1, h1) << endl;

    // Classic LeetCode example — expected 4
    vector<int> piles2 = {3, 6, 7, 11};
    int h2 = 8;
    cout << "Test 2 (expected 4): " << sol.minEatingSpeed(piles2, h2) << endl;

    // Another common example — expected 30
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 5;
    cout << "Test 3 (expected 30): " << sol.minEatingSpeed(piles3, h3) << endl;

    // Edge case — expected 23
    vector<int> piles4 = {30, 11, 23, 4, 20};
    int h4 = 6;
    cout << "Test 4 (expected 23): " << sol.minEatingSpeed(piles4, h4) << endl;

    return 0; //
}