// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n, mini = 0, temp = 0;
    cout << "Enter the number of array elements you want: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at array index " << i + 1 << " : ";
        cin >> arr[i];
    }

    // selection sort
    for (int i = 0; i <= n - 2; i++)
    {
        mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    cout << "Sorted array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}