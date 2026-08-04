#include <bits/stdc++.h>
using namespace std;

int findNumberThatAppearsOnce(vector<int> &a, int n)
{
    int xored = 0;

    for (int i = 0; i < n; i++)
    {
        xored = xored ^ a[i];
    }

    return xored;
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

    // Find the number that appears Once
    int appearOnce = findNumberThatAppearsOnce(a, n);

    cout << "Number that appears exactly once: " << appearOnce;

    return 0;
}
//