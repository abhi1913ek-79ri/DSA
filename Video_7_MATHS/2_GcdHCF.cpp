#include<bits/stdc++.h>
using namespace std;
// GCD or HCF
// Here I just use euclodian algo
int HCF(int a,int b){
    while(a>0&&b>0){
        if(a>b) a=a%b;
        else b=b%a;    }
    return (a == 0) ? b : a;
}


int main(){
    int a,b;
    a=10;
    b=15;
    cout<<"GCD of "<<a<<","<<b<<" is : "<<HCF(a,b);
    return 0;
}