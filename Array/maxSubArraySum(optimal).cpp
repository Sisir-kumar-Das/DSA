#include <bits/stdc++.h>
using namespace std;

int maximuSubarraySumFunc(vector<int> &a)
{
    long long sum = 0, max = LONG_MIN;

    for (int i = 0; i < a.size(); i++)
    {

        sum += a[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }

    return max;
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

    // maximum subarray sum
    int maximuSubarraySum = maximuSubarraySumFunc(a);

    cout << "Majority element is: " << maximuSubarraySum;

    return 0;
}