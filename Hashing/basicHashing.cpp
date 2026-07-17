// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n;
    cout << "Enter length of array :";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value at array index " << i + 1 << " :";
        cin >> arr[i];
    }

    // prestoring
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    // fetching
    int q;
    cout << "Enter how many elements you want to search:";
    cin >> q;

    while (q--)
    {
        int num;
        cout << "Enter  number:";
        cin >> num;
        cout << "The no of times this number present in the array is: " << hash[num] << endl;
    }

    return 0;
}