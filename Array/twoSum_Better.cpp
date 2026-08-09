#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumFumc(vector<int> &a, int target)
{
    map<int, int> mp;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int value = a[i];
        int more = target - value;
        if (mp.find(more) != mp.end())
        {
            return {mp[more], i};
        }
        mp[value] = i;
    }
    return {};
}

int main()
{
    // Write C++ code here
    int n, target;
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

    cout << "Enter the target value: ";
    cin >> target;

    // Find two sum
    vector<int> twoSum = twoSumFumc(a, target);
    if (!twoSum.empty())
        cout << "Indices: " << twoSum[0] << ", " << twoSum[1] << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}