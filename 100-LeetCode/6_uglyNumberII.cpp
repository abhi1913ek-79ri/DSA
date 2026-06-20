#include<bits/stdc++.h>
using namespace std;
// TLE
// Ugly number II
bool isUgly(int n){
    while (n%2==0) n/=2;
    while (n%3==0) n/=3;
    while (n%5==0) n/=5;
    return n==1;
}

int nthUglyNumber_native(int n) {
    int cnt = 1;
    int i = 1;
    while (cnt!=n)
    {
        i++;
        if(isUgly(i)) cnt++;
    }
    return i;
    //TC =  Not defind 
}


int main(){
    int n = 10;
    cout << n<< "th Ugly num : " << nthUglyNumber_native(n)<<endl;
    return 0;
}