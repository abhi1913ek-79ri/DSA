#include<bits/stdc++.h>
using namespace std;
// Sum of series
int sum=0;
int sumOfSeries(int n) {
    // code here
    if(n<=1) return 1;
    return n*n*n+sumOfSeries(n-1);
}

int main(){
    cout << sumOfSeries(5);
    return 0;
}