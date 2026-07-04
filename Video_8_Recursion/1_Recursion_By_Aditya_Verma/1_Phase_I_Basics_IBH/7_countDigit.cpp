#include<bits/stdc++.h>
using namespace std;
// count digit

// hypothesis
// countDigit(n/10) = correctly return num of digit in n/10;

// induction
// countDigit(n) = 1+ countDigit(n/10)

// base condition
// n == 0 return 0;

// edge case 
// n == 0 initialy then CD return 1


int cDHelper(int n){
    // base condition
    if(n == 0) return 0;

    // recursive call
    return 1 + cDHelper(n/10);
}

int countDigit(int n){
    if(n == 0) return 1;
    return cDHelper(n);
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countDigit(n) << "\n";
    }
    return 0;
}