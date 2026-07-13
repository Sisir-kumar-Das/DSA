// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void name(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    name(n - 1);
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    name(n);

    return 0;
}