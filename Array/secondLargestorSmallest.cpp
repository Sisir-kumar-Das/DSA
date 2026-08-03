#include <bits/stdc++.h>
using namespace std;
//
int secondLarge(int arr[], int n)
{
    int largest = arr[0];
    int secLargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && secLargest < arr[i])
        {
            secLargest = arr[i];
        }
    }
    return secLargest;
}

int secondSmall(int arr[], int n)
{
    int smallest = arr[0];
    int secSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && secSmallest > arr[i])
        {
            secSmallest = arr[i];
        }
    }
    return secSmallest;
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
    int secondLargest = secondLarge(arr, n);
    int secondSmallest = secondSmall(arr, n);

    cout << "Second Smallest is " << secondSmallest << endl;
    cout << "Second Largest is " << secondLargest;

    return 0;
}