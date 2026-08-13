#include <bits/stdc++.h>
using namespace std;

vector<int> neaxtPerumtation(vector<int> &a)
{
    int index = -1;
    int n = a.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    for (int i = n - 1; i >= index; i--)
    {
        if (a[index] < a[i])
        {
            swap(a[i], a[index]);
            break;
        }
    }
    reverse(a.begin() + index + 1, a.end());
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

    // next permutation
    vector<int> ans = neaxtPerumtation(a);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}