// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    vector<int> vect;
    int n, o;
    cout << "Enter the number of elements you want: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Please Enter the value: " << endl;
        cin >> x;
        vect.push_back(x);
    }
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[vect[i]]++;
    }

    cout << "Enter the number of values to check: ";
    cin >> o;
    for (int i = 0; i < o; i++)
    {
        int x;
        cout << "Enter value to hash: ";
        cin >> x;
        cout << x << " occurs " << mpp[x] << " time(s)" << endl;
    }

    return 0;
}