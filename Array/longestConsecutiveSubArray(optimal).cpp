#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubaArray(vector<int> &a)
{
    int n = a.size();
    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
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

    // longest Conesecutive subarray
    int ans = longestConsecutiveSubaArray(a);

    cout << ans << " ";
    return 0;
}