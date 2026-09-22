#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long long low = 1, high = x;

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if ((mid * mid) <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

int main()
{
    Solution sol;

    vector<int> tests = {0, 1, 2, 3, 4, 8, 9, 15, 16, 2147395599, 2147483647};

    for (int x : tests)
    {
        cout << "sqrt(" << x << ") = " << sol.mySqrt(x) << endl;
    }

    return 0;
}