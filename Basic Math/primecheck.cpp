// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write C++ code here
    int n, i, count = 0;

    cout << "Enter a number: ";
    cin >> n;
    for (i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        cout << "This is a prime number";
    }
    else
    {
        cout << "This is not a prime number";
    }
}