#include<bits/stdc++.h>
using namespace std;
// Ugly Number is a number which doesn't have prime factor other than 2,3,5
bool isUgly(int n) {
    for(int i=2;i*i<=n;i++) {
        while (n%i==0)
        {
            if(i > 5) return false;
            n/=i;
        }
        // if(i>5&&n>0) return false; wrong position
    }

    return n==1 || n==2 || n==3 || n==5;
    // TC = O(logn)
}

// clean code
bool isUglyClean(int n){
    while (n%2==0) n/=2;
    while (n%3==0) n/=3;
    while (n%5==0) n/=5;
    return n==1;
}
int main(){
    int n = 7;
    cout <<n<< " is " << (isUglyClean(n)?" Ugly.":" non Ugly.") << endl;
    return 0;
}