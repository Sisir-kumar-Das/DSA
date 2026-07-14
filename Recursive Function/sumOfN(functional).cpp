// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int sumOfN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumOfN(n - 1);
}

int main()
{
    // Write C++ code here
    int n, sum = 0, total;
    cout << "Enter a nummber :";
    cin >> n;
    total = sumOfN(n);
    cout << "Total : " << total;
    return 0;
}