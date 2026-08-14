#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubaArray(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int longest = 1, cnt = 0, lastSmaller = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            cnt++;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }

    return longest;
}

int main()
{
    // Write C++ code here
    int n;
    cout << "Enter the number of array elements you want in vector a: ";
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the value of arr a at vector index " << i << " : ";
        cin >> x;
        a.push_back(x);
    }

    // longest Conesecutive subarray
    int ans = longestConsecutiveSubaArray(a);

    cout << ans << " ";
    return 0;
}