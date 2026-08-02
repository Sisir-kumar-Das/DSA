#include <bits/stdc++.h>
using namespace std;

int missingNumberFunc(vector<int> &a, int n)
{
    vector<int> hash(n + 1, 0);

    // prestoring
    for (int i = 0; i < n; i++)
    {
        hash[a[i]] += 1;
    }

    // fetching
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
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