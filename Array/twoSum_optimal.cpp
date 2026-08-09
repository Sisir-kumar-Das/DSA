#include <bits/stdc++.h>
using namespace std;

string twoSumFumc(vector<int> &a, int target)
{
    int n = a.size();
    int left = 0, right = n - 1;
    sort(a.begin(), a.end());
    while (left < right)
    {
        int sum = a[left] + a[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO";
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
    string twoSum = twoSumFumc(a, target);
    cout << twoSum;

    return 0;
}