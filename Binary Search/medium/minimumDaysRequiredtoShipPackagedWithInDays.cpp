#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
private:
    int noOfDaysRequired(vector<int> &weights, int capacity)
    {
        int days = 1, load = 0, n = weights.size();
        for (int i = 0; i < n; i++)
        {
            if (load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            int daysRequired = noOfDaysRequired(weights, mid);
            if (daysRequired <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main()
{
    Solution sol;

    // Test 1: expected 15
    vector<int> w1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sol.shipWithinDays(w1, 5) << "\n";

    // Test 2: expected 6
    vector<int> w2 = {3, 2, 2, 4, 1, 4};
    cout << sol.shipWithinDays(w2, 3) << "\n";

    // Test 3: expected 3
    vector<int> w3 = {1, 2, 3, 1, 1};
    cout << sol.shipWithinDays(w3, 4) << "\n";

    return 0;
}