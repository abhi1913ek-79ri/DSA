#include<bits/stdc++.h>
using namespace std;
// count primes in  range L to r in range 
// L to r 
// Segmented Sieve of erastosthenes

// count primes from 1 to n including n -- normal sieve
int countPrimes(int l,int r){
    if(r<=2) return 0;

    vector<bool> primes(r+1,true);

    primes[0] = primes[1] = false;

    for(int i = 2;i*i <= r ;i++){
        if(primes[i]){
            for(int j=i*i;j<=r;j+=i){
                primes[j]= false;
            }
        }
    }

    int cnt = 0;
    for(int i = l;i<=r;i++){
        if(primes[i]) cnt++;
    }
    return cnt;
}



int main(){
    vector<int> range = {2, 10};

    cout << "Primes Cnt : " << countPrimes(range[0],range[1]);
    
    return 0;
}