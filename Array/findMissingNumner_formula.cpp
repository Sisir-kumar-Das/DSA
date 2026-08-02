#include <bits/stdc++.h>
using namespace std;

int missingNumberFunc(vector<int> &a, int n)
{
    long long int actualSum = 0, expectedSum;

    for (int i = 0; i < n; i++)
    {
        actualSum += a[i];
    }
    // true range is 1 to n, array has n-1 elements
    n = n + 1;
    expectedSum = (n * 1LL * (n + 1)) / 2;

    return expectedSum - actualSum;
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

    // Find missing Number
    int missingNumber = missingNumberFunc(a, n);

    if (missingNumber == -1)
    {
        cout << "No missing Number found";
    }
    else
    {
        cout << "Missing number is : " << missingNumber;
    }

    return 0;
}
//