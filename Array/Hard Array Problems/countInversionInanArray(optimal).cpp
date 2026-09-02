#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i = left;    // starting index for left subarray
    int j = mid + 1; // starting index for right subarray
    int k = left;    // starting index to be sorted
    long long invCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // arr[i] > arr[j], so all remaining elements in left subarray
            // (from i to mid) are greater than arr[j] -> inversions found
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray, if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted subarray back into original array
    for (int idx = left; idx <= right; idx++)
        arr[idx] = temp[idx];

    return invCount;
}

long long mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    long long invCount = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

long long countInversions(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main()
{
    vector<int> arr = {8, 4, 2, 1};
    cout << "Number of inversions: " << countInversions(arr) << endl;

    vector<int> arr2 = {3, 1, 2};
    cout << "Number of inversions: " << countInversions(arr2) << endl;

    return 0;
}