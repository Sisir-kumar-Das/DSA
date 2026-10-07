#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <random>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

// Brute force: merge, sort, take the median
double bruteForce(vector<int> a, vector<int> b)
{
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    int n = a.size();
    if (n % 2)
        return a[n / 2];
    return ((double)a[n / 2 - 1] + (double)a[n / 2]) / 2.0;
}

int main()
{
    Solution sol;

    // Hardcoded cases
    vector<pair<vector<int>, vector<int>>> tests;
    tests.push_back(make_pair(vector<int>{1, 3}, vector<int>{2}));                // 2.0
    tests.push_back(make_pair(vector<int>{1, 2}, vector<int>{3, 4}));             // 2.5
    tests.push_back(make_pair(vector<int>{}, vector<int>{1}));                    // 1.0
    tests.push_back(make_pair(vector<int>{0, 0}, vector<int>{0, 0}));             // 0.0
    tests.push_back(make_pair(vector<int>{INT_MAX}, vector<int>{INT_MAX}));       // 2147483647
    tests.push_back(make_pair(vector<int>{INT_MIN}, vector<int>{INT_MIN}));       // -2147483648
    tests.push_back(make_pair(vector<int>{1, 2, 3, 4, 5}, vector<int>{6, 7, 8})); // 4.5

    cout << "--- Hardcoded tests ---\n";
    for (size_t i = 0; i < tests.size(); i++)
    {
        vector<int> &a = tests[i].first;
        vector<int> &b = tests[i].second;
        double got = sol.findMedianSortedArrays(a, b);
        double want = bruteForce(a, b);
        cout << "got = " << got << ", expected = " << want
             << (got == want ? "  OK" : "  MISMATCH") << "\n";
    }

    // Random tests against brute force
    cout << "\n--- Random tests ---\n";
    mt19937 rng(12345);
    int failures = 0;
    for (int t = 0; t < 10000; t++)
    {
        int s1 = rng() % 8, s2 = rng() % 8;
        if (s1 + s2 == 0)
            s2 = 1; // at least one element total

        vector<int> a(s1), b(s2);
        for (size_t i = 0; i < a.size(); i++)
            a[i] = (int)(rng() % 41) - 20;
        for (size_t i = 0; i < b.size(); i++)
            b[i] = (int)(rng() % 41) - 20;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        double got = sol.findMedianSortedArrays(a, b);
        double want = bruteForce(a, b);
        if (got != want)
        {
            failures++;
            cout << "MISMATCH: got " << got << ", expected " << want << "\n";
            if (failures >= 5)
                break;
        }
    }
    cout << (failures == 0 ? "All random tests passed\n" : "Some random tests failed\n");

    return 0;
}