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

    // Insertion Sort sort
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "Sorted array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}