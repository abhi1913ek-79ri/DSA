#include<bits/stdc++.h>
using namespace std;

// parametrised - not returning something justchnage the parameters 
void fact1(int n,int fact){
    if(n<1){
        cout << fact;
        return;
    }

    fact1(n-1,fact*n);
}

// functional way which take only n and return desired ans 
int fact2(int n){
    if(n < 1) return 1;
    return n*fact2(n-1);
}

int main(){
    int n = 6;
    int fact = 1;
    // fact1(n,fact);
    cout << "Factorial of " << n << " is "<< fact2(n);
    return 0;
}