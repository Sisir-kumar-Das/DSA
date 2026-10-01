#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countStudents(vector<int> arr, int pages)
    {
        int n = arr.size();
        int students = 1;
        long long pageStudents = 0;
        for (int i = 0; i < n; i++)
        {
            if (pageStudents + arr[i] <= pages)
                pageStudents += arr[i];
            else
            {
                students += 1;
                pageStudents = arr[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &arr, int n, int m)
    {
        if (m > n)
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            if (students > m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        return findPages(nums, nums.size(), k);
    }
};

int main()
{
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << sol.splitArray(nums, k) << endl;
    return 0;
}