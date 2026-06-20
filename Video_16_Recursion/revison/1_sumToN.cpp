#include<bits/stdc++.h>
using namespace std;


// Parametrised way of sumN
void sumN1(int n,int sum){
    if(n == 0){
        cout<< sum;
        return;
    }

    sumN1(n-1,sum+n);
}

// functional way -- that is to return something as answer not take parameter and just change the parameter
int sumN(int n){
    if(n==0) return 0;
    return sumN(n-1)+n;
}


// other methods 
int sumN3(int n){
    return n*(n+1)/2;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    // sumN1(n,0);

    int sum = sumN3(n);
    cout << "Sum of 1 to " << n << " is :" << sum;
    return 0;
}