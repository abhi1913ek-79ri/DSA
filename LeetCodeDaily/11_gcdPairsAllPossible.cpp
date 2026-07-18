#include<bits/stdc++.h>
using namespace std;
// gcd all possible pairs 
int gcd(int a, int b){
    while (b)
    {
        int temp = a;
        a = b;
        b = temp%a;
    }
    
}

int main(){
    
    return 0;
}