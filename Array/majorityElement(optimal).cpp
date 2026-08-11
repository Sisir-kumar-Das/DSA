#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a)
{
    int cnt = 0, el;

    for (int i = 0; i < a.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = a[i];
        }
        else if (a[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (el == a[i])
        {
            cnt1++;
        }
    }
    if (cnt1 > (a.size() / 2))
        return el;
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

    cout << "Majority element is: " << major;

    return 0;
}