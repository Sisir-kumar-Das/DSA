// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, value;
    cout << "Enter a Number: ";
    cin >> n;
    value = fibonacci(n);
    cout << "Value at n th index in fibonnaci series is:" << value;
}