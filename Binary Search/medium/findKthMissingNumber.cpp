#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};

// Brute force for verification
int bruteForce(const vector<int> &arr, int k)
{
    set<int> s(arr.begin(), arr.end());
    int num = 0;
    while (k > 0)
    {
        num++;
        if (!s.count(num))
            k--;
    }
    return num;
}

int main()
{
    Solution sol;

    // Example tests
    vector<int> a1 = {2, 3, 4, 7, 11};
    cout << "Test 1: " << sol.findKthPositive(a1, 5) << " (expected 9)\n";

    vector<int> a2 = {1, 2, 3, 4};
    cout << "Test 2: " << sol.findKthPositive(a2, 2) << " (expected 6)\n";

    // Randomized testing
    mt19937 rng(42);
    for (int t = 0; t < 10000; t++)
    {
        int n = rng() % 15 + 1;
        set<int> st;
        while ((int)st.size() < n)
            st.insert(rng() % 50 + 1);
        vector<int> arr(st.begin(), st.end()); // sorted & unique
        int k = rng() % 30 + 1;

        int got = sol.findKthPositive(arr, k);
        int exp = bruteForce(arr, k);
        if (got != exp)
        {
            cout << "MISMATCH! k=" << k << " arr=[";
            for (int x : arr)
                cout << x << " ";
            cout << "] got=" << got << " expected=" << exp << "\n";
            return 1;
        }
    }
    cout << "All 10000 random tests passed!\n";
    return 0;
}