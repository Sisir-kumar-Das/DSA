#include <bits/stdc++.h>
using namespace std;

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

    // Bubble sort
    for (int i = n - 1; i >= 1; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
    }

    cout << "Sorted array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}