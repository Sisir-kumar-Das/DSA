// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void sumOfN(int sum, int n){
    if(n ==0){
        cout<<"Total :" << sum;
        return ;
    }
    sum = sum + n;
    sumOfN(sum, n-1);
}

int main() {
    // Write C++ code here
    int n, sum = 0, total;
    cout << "Enter a nummber :";
    cin >> n;
    sumOfN(sum, n);
    
    return 0;
}