// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter 1st number: ";
    cin >> a;
    cout << "Enter 2nd number: ";
    cin >> b;

    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout << "Gcd is: " << b;
    else
        cout << "Gcd is: " << a;
}