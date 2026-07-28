#include <bits/stdc++.h>
using namespace std;

int checkArraySorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
            return false;
    }
    return true;
}

int main()
{
    // Write C++ code here
    int n, mini = 0;
    cout << "Enter the number of array elements you want: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at array index " << i + 1 << " : ";
        cin >> arr[i];
    }

    // second Largest and Second Smallest
    bool sorted = checkArraySorted(arr, n);
    if (sorted)
        cout << "This is an sorted array";
    else
        cout << "This is not an Sorted array";

    return 0;
}