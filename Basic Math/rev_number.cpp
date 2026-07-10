// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write C++ code here
    int n, rev = 0, last_digit = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n > 0)
    {
        last_digit = n % 10;
        rev = (rev * 10) + last_digit;
        n /= 10;
    }
    cout << "Rev: " << rev << endl;
    return 0;
}