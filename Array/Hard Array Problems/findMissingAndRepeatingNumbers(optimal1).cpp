#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMissingRepeating(vector<int> &arr)
{
    long long n = arr.size();

    long long actualSum = 0, actualSumSq = 0;
    for (int i = 0; i < n; i++)
    {
        actualSum += arr[i];
        actualSumSq += (long long)arr[i] * (long long)arr[i];
    }

    long long expectedSum = n * (n + 1) / 2;
    long long expectedSumSq = n * (n + 1) * (2 * n + 1) / 6;

    long long S = expectedSum - actualSum;      // x - y
    long long S2 = expectedSumSq - actualSumSq; // x^2 - y^2

    long long sumXY = S2 / S;      // x + y
    long long x = (S + sumXY) / 2; // missing
    long long y = x - S;           // repeating

    return make_pair((int)x, (int)y);
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 6};

    pair<int, int> result = findMissingRepeating(arr);
    int missing = result.first;
    int repeating = result.second;

    cout << "Missing number: " << missing << "\n";
    cout << "Repeating number: " << repeating << "\n";

    return 0;
}