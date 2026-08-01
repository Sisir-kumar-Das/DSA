#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfArray(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;
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
    vector<int> unionArr;
    unionArr = unionOfArray(a, b);

    for (auto it : unionArr)
    {
        cout << it << " ";
    }

    return 0;
}
//