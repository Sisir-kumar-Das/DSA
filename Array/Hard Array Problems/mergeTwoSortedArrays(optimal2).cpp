#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
    {
        if (arr1[ind1] > arr2[ind2])
        {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;

            while (right < len)
            {
                if (left < m && right >= m)
                {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                else if (left >= m)
                {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                else
                {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++, right++;
            }

            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }

        // copy the now-sorted nums2 into nums1's trailing placeholder slots
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    }
};

void printVec(const vector<int> &v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ",";
    }
    cout << "]";
}

void runTest(vector<int> nums1, int m, vector<int> nums2, int n, vector<int> expected)
{
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    cout << "Output:   ";
    printVec(nums1);
    cout << "\nExpected: ";
    printVec(expected);
    cout << "\nResult:   " << (nums1 == expected ? "PASS" : "FAIL") << "\n\n";
}

int main()
{
    runTest({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}); // your failing case
    runTest({1}, 1, {}, 0, {1});                                      // n = 0 edge case
    runTest({0, 0, 0}, 0, {1, 2, 3}, 3, {1, 2, 3});                   // m = 0 edge case
    runTest({4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}); // interleaved
    runTest({1, 3, 0, 0}, 2, {2, 4}, 2, {1, 2, 3, 4});                // nums2 all larger

    return 0;
}