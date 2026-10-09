#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return kthElement(nums2, nums1, k);

        int low = max(k - n2, 0), high = min(k, n1);
        int left = k;

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
                return max(l1, l2);
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

// Brute force: merge, sort, pick k-th (1-indexed)
int bruteForce(vector<int> a, vector<int> b, int k)
{
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    return a[k - 1];
}

int main()
{
    Solution sol;

    // Sample from the screenshot (expected 256)
    vector<int> A = {100, 112, 256, 349, 770};
    vector<int> B = {72, 86, 113, 119, 265, 445, 892};
    cout << "Sample: " << sol.kthElement(A, B, 7) << " (expected 256)\n";

    // Edge cases
    vector<int> a1 = {1}, b1 = {2};
    cout << "k=1: " << sol.kthElement(a1, b1, 1) << " (expected 1)\n";
    cout << "k=2: " << sol.kthElement(a1, b1, 2) << " (expected 2)\n";

    vector<int> a2 = {1, 2, 3}, b2 = {4, 5, 6};
    cout << "All A before B, k=4: " << sol.kthElement(a2, b2, 4) << " (expected 4)\n";
    cout << "Swapped, k=4: " << sol.kthElement(b2, a2, 4) << " (expected 4)\n";

    // Random stress test against brute force
    mt19937 rng(12345);
    int failures = 0;
    for (int t = 0; t < 100000; t++)
    {
        int n = rng() % 10 + 1;
        int m = rng() % 10 + 1;
        vector<int> a(n), b(m);
        for (auto &x : a)
            x = rng() % 50;
        for (auto &x : b)
            x = rng() % 50;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = rng() % (n + m) + 1;

        int expected = bruteForce(a, b, k);
        int got = sol.kthElement(a, b, k);
        if (got != expected)
        {
            failures++;
            cout << "MISMATCH k=" << k << " got=" << got << " expected=" << expected << "\n";
            if (failures >= 5)
                break;
        }
    }
    cout << (failures == 0 ? "Stress test passed" : "Stress test FAILED") << "\n";
    return 0;
}