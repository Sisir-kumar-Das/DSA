// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void reverseArray(int i, int arr[], int n)
{
    if (i == n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reverseArray(i + 1, arr, n);
}

int main()
{
    // Write C++ code here
    int n, sum = 0;
    cout << "Enter a nummber :";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value at position " << i + 1 << " : " << endl;
        cin >> arr[i];
    }
    reverseArray(0, arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}