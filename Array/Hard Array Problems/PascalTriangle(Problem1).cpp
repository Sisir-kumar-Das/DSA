#include <bits/stdc++.h>
using namespace std;

long long pascalTriangle(int r, int c)
{
    long long res = 1;

    for (int i = 0; i < c; i++)
    {
        res = res * (r - i);
        res = res / (i + 1);
    }

    return res;
}

int main()
{
    int r, c;

    cout << "Enter the row number at which you want to find element: ";
    cin >> r;
    cout << "Enter the column number at which you want to find element: ";
    cin >> c;

    // pascal traingle
    long long value = pascalTriangle(r - 1, c - 1);

    cout << "The value in pascal triangle is: " << value;

    return 0;
}