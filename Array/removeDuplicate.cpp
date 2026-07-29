#include <bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    // Write C++ code here
    int n;
    cout << "Enter the number of array elements you want: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at array index (in sorted order) " << i + 1 << " : ";
        cin >> arr[i];
    }

    // second Largest and Second Smallest
    int uniqueElementsCount = removeDuplicate(arr, n);

    cout << "No. of Unique elements in array: " << uniqueElementsCount;
    return 0;
}