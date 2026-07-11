// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write C++ code here
    int n, sum = 0, copy_n = 0, last_digit = 0;

    cout << "Enter a number: ";
    cin >> n;
    copy_n = n;

    while (copy_n > 0)
    {
        last_digit = copy_n % 10;
        sum += (last_digit * last_digit * last_digit);
        copy_n /= 10;
    }

    if (n == sum)
    {
        cout << "This is a armstrong  number.";
    }
    else
    {
        cout << "This is not a armstrong number";
    }
    return 0;
}