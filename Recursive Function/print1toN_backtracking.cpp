// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void name(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    name(i - 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    name(n, n);

    return 0;
}