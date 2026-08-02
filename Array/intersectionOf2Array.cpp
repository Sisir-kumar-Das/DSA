#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionofArrays(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> intersection;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }
    return intersection;
}

int main()
{
    // Write C++ code here
    int n1, n2;
    cout << "Enter the number of array elements you want in vector a: ";
    cin >> n1;
    cout << "Enter the number of array elements you want in vector b: ";
    cin >> n2;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cout << "Enter the value of arr a at vector index " << i << " : ";
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        int x;
        cout << "Enter the value of arr b at vector index " << i << " : ";
        cin >> x;
        b.push_back(x);
    }

    // union array
    vector<int> intersection;
    intersection = intersectionofArrays(a, b);

    for (auto it : intersection)
    {
        cout << it << " ";
    }

    return 0;
}
//