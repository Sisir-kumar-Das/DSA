#include <bits/stdc++.h>
using namespace std;

vector<int> reArrangeFunc(vector<int> &a)
{
    int n = a.size();
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            ans[negIndex] = a[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
    }

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

    // Rearrang the array elemts by sign (Equal no of sign)
    vector<int> ans = reArrangeFunc(a);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}