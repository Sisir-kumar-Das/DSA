#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = m - 1;
        int right = 0;

        while (left >= 0 && right < n)
        {
            if (nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else
                break;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
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

int main()
{
    Solution sol;

    // Test case: the one that fails
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Output:   ";
    printVec(nums1);
    cout << endl;

    cout << "Expected: [1,2,2,3,5,6]" << endl;

    return 0;
}