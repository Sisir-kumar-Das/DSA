#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int func(int mid, int N, int M)
    {
        long long ans = 1;
        for (int i = 1; i <= N; i++)
        {
            ans = ans * mid;
            if (ans > M)
                return 2;
        }
        if (ans == M)
            return 1;
        return 0;
    }

public:
    int NthRoot(int N, int M)
    {
        int low = 1, high = M;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int result = func(mid, N, M);
            if (result == 1)
                return mid;
            else if (result == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int N, M;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter M: ";
    cin >> M;

    Solution sol;
    int ans = sol.NthRoot(N, M);

    if (ans == -1)
        cout << "No integer Nth root exists for M = " << M << " with N = " << N << endl;
    else
        cout << "The " << N << "th root of " << M << " is: " << ans << endl;

    return 0;
}