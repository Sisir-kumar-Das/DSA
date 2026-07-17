// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    string str;
    cout << "Enter the string :";
    cin >> str;

    // prestoring
    int hash[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        hash[str[i] - 'a']++;
    }

    // fetching
    int q;
    cout << "Enter how many elements you want to hash:";
    cin >> q;

    while (q--)
    {
        char ch;
        cout << "Enter  caracter:";
        cin >> ch;
        cout << "The no of times this character present in the string is: " << hash[ch - 'a'] << endl;
    }

    return 0;
}