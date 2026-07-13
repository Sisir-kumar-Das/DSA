// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void name(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << "Sisir" << endl;
    name(i + 1, n);
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    name(1, n);

    return 0;
}