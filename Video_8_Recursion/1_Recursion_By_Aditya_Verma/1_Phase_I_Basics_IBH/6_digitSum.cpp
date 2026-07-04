#include<bits/stdc++.h>
using namespace std;
// digit sum 

// hyphothesis
// sumDigit(n/10) = returns sum of digit in (n/10);

// induction
// sumDigit(n) = lastDigit + sumDigit(n/10) 

// base condition
// n == 0 return 0;
int sumDigit(int n){
    // base condition
    if(n==0) return 0;

    int digit = n%10;
    // recursive call
    return digit+sumDigit(n/10);
}


int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sumDigit(n) << "\n";
    }
    return 0;
}