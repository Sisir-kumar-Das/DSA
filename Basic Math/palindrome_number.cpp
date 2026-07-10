// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write C++ code here
    int n, rev = 0, last_digit = 0, copy_n;

    cout << "Enter a number: ";
    cin >> n;
    copy_n = n;

    while (copy_n > 0)
    {
        last_digit = copy_n % 10;
        rev = (rev * 10) + last_digit;
        copy_n /= 10;
    }

    if (n == rev)
    {
        cout << "This is a palindrome number.";
    }
    else
    {
        cout << "This is not a palindrome number";
    }
    return 0;
}