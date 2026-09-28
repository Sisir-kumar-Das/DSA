#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int count = 0;
        int noOfB = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                noOfB += count / k;
                count = 0;
            }
        }
        noOfB += count / k;
        return noOfB >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if ((long long)m * k > n)
            return -1; // overflow-safe

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k))
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

    struct Test
    {
        vector<int> bloomDay;
        int m, k;
        int expected;
    };

    vector<Test> tests = {
        {{1, 10, 3, 10, 2}, 3, 1, 3},
        {{1, 10, 3, 10, 2}, 3, 2, -1},
        {{7, 7, 7, 7, 12, 7, 7}, 2, 3, 12},
        {{1000000000, 1000000000}, 1, 1, 1000000000},
    };

    for (int i = 0; i < tests.size(); i++)
    {
        int got = sol.minDays(tests[i].bloomDay, tests[i].m, tests[i].k);
        cout << "Test " << i + 1 << ": got " << got
             << ", expected " << tests[i].expected
             << (got == tests[i].expected ? "  PASS" : "  FAIL") << "\n";
    }
    return 0;
}