#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int count = 0;

private:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && arr[i] > 2LL * arr[right])
                right++;
            count += right - (mid + 1);
        }
    }

    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        count = 0; // reset in case the object is reused across calls
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return count;
    }
};

int main()
{
    // Test case 1
    vector<int> nums1 = {1, 3, 2, 3, 1};
    Solution sol1;
    cout << "Test 1: " << sol1.reversePairs(nums1) << " (expected 2)" << endl;

    // Test case 2 (the one from your screenshot)
    vector<int> nums2 = {2, 4, 3, 5, 1};
    Solution sol2;
    cout << "Test 2: " << sol2.reversePairs(nums2) << " (expected 3)" << endl;

    // Test case 4
    vector<int> nums3 = {2, 4, 3, 5, 1};
    Solution sol3;
    cout << "Test 3: " << sol3.reversePairs(nums3) << " (expected 3)" << endl;

    return 0;
}