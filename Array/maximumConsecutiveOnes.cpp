#include <bits/stdc++.h>
using namespace std;

int maximumConsecutiveOnes(vector<int> &a, int n)
{
    int maximum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count++;
            if (maximum < count)
                maximum = count;
        }
        else
        {
            count = 0;
        }
    }

    return maximum;
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

    // Maximum consecutive ones
    int cnsecutiveOnes = maximumConsecutiveOnes(a, n);

    cout << "Maximum ones : " << cnsecutiveOnes;

    return 0;
}
//