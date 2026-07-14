// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    // Write C++ code here
    int n, sum = 0, fact;
    cout << "Enter a nummber :";
    cin >> n;
    fact = factorial(n);
    cout << "Factorial : " << fact;
    return 0;
}