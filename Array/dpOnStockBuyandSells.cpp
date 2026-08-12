#include <bits/stdc++.h>
using namespace std;

int buyandSellsFunc(vector<int> &a)
{
    int n = a.size();
    int mini = a[0], maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        int cost = a[i] - mini;
        maxProfit = max(cost, maxProfit);
        mini = min(mini, a[i]);
    }
    return maxProfit;
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

    // DP on stocks buy and sells
    int maxProfit = buyandSellsFunc(a);

    cout << "Max profit is: " << maxProfit;

    return 0;
}