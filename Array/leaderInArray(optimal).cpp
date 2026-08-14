#include <bits/stdc++.h>
using namespace std;

vector<int> leadersInArray(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;

    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
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

    // Leaders in an array
    vector<int> ans = leadersInArray(a);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}