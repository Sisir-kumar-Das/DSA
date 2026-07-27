#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the number of elements you want: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the value at position " << i + 1 << " :";
        cin >> x;
        arr.push_back(x);
    }
    quickSort(arr, 0, n - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}