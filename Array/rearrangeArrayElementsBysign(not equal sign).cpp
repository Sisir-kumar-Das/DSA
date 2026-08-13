#include <bits/stdc++.h>
using namespace std;

vector<int> reArrangeFunc(vector<int> &a)
{
    int n = a.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    if (pos.size() > neg.size())
    {

        for (int i = 0; i < neg.size(); i++)
        {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }

        int index = neg.size() * 2;

        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
        int index = pos.size() * 2;

        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[index] = neg[i];
            index++;
        }
    }

    return a;
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