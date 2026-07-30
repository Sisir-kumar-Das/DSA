#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Write C++ code here
    int n, num;
    cout << "Enter the number of array elements you want: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at array index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Enter the num you want to search : ";
    cin >> num;

    // move zero to end
    int index = linearSearch(arr, n, num);

    cout << "The number is at index: " << index;
    return 0;
}