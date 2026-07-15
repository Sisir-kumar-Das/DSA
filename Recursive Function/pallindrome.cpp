// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool checkPallindrome(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return checkPallindrome(i + 1, s);
}

int main()
{
    // Write C++ code here
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (checkPallindrome(0, s))
        cout << "This is a pallindrome string.";
    else
        cout << "This is a not pallindrome string.";
    return 0;
}