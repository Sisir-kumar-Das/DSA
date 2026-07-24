#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int i, int n)
{
    if (i == n)
        return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertionSort(arr, i + 1, n);
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

    // Insertion Sort Recursive
    insertionSort(arr, 0, n);

    cout << "Sorted array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}