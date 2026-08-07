#include <bits/stdc++.h>
using namespace std;

int maxLengthSubArray(vector<int> &a, int k)
{
    int right = 0, left = 0;
    int maxLen = 0;
    long long sum = 0;
    int n = a.size();

    while (right < n)
    {
        sum += a[right]; // include current element first

        while (left <= right && sum > k) // shrink from left if too big
        {
            sum -= a[left];
            left++;
        }

        if (sum == k) // now check with a correct sum
            maxLen = max(maxLen, right - left + 1);

        right++;
    }
    return maxLen;
}

int main()
{
    // Write C++ code here
    int n, k;
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

    cout << "Please enter value of k: ";
    cin >> k;
    // Find missing Number
    int maxLength = maxLengthSubArray(a, k);

    cout << "Maximum length of the subarray is : " << maxLength;

    return 0;
}
//