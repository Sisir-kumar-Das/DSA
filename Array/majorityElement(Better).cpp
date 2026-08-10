#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a)
{
    int n = a.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > (n / 2))
            return it.first;
    }
    return -1;
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

    // majority element  > n/2
    int major = majorityElement(a);

    cout << major << " ";

    return 0;
}