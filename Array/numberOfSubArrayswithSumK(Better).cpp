#include <bits/stdc++.h>
using namespace std;

int noOfSubarraysFunc(vector<int> &a, int k)
{
    int n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
                count++;
        }
    }

    return count;
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

    cout << "Enter the sum of sub-array : ";
    cin >> k;

    // Number of subarray with sum k
    int noOfSubArrays = noOfSubarraysFunc(a, k);

    cout << "No of subarrays with sum" << k << "is: " << noOfSubArrays;

    return 0;
}