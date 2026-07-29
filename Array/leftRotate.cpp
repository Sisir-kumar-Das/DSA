#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int d)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

int main()
{
    // Write C++ code here
    int n, d;
    cout << "Enter the number of array elements you want: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at array index (in sorted order) " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "Enter the no. of left rotation you want: ";
    cin >> d;

    // Left rotation optimal
    leftRotate(arr, n, d);

    cout << "After left rotating array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}