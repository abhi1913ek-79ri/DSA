#include<bits/stdc++.h>
using namespace std;
// count primes less than n
// brute force
// isprime
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return false;
    }
    return true;
}

int countPrimes(int n){
    int cnt = 0;
    for(int i = 2;i<n;i++){
        if(isPrime(i)) cnt++;
    }
    return cnt;
    // TC = n*sqrt(n) -- TLE for 10^6
    // SC = O(1)
}

// Optimal : 
// Sieve of erastostenes
int countPrimes1ToN(int n){
    // marks all these numbers as prime
    vector<int> primes(n,1);

    // marks 0 and1 as non prime
    primes[0]=primes[1]=0;
    
    // main - idea -- precomputation - Nlog(logN)
    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){ 
                primes[j]=0;
            }
        }
    }

    // check for primes and return the count
    int primeCnt = 0;
    for(auto num : primes){
        if(num==1) primeCnt++;
    }

    return primeCnt;
    // TC = O(nloglogn)
    // SC = O(n)
}


int main(){
    int n = 10;
    cout << "Prime Count : " << countPrimes1ToN(n) << endl;
    
    return 0;
}