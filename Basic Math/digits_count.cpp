
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, count = 0, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n > 0)
    {
        sum += n % 10;
        count++;
        n /= 10;
    }
    cout << "Sum: " << sum << endl;
    cout << "Count: " << count << endl;
    return 0;
}