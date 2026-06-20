#include<bits/stdc++.h>
using namespace std;
// primeNumber
string isPrime(int n) {
    if (n <= 1) return "Non prime."; // Handle numbers <= 1
    for (int i = 2; i * i <= n; i++) { // Loop up to sqrt(n)
        if (n % i == 0) {
            return "Non prime."; // If divisible, it's not prime
        }
    }
    return "Prime."; // If no divisors found, it's prime
}

int main(){
    cout<<"The number "<<153<<" is  "<<isPrime(153)<<""<<endl;
    return 0;
}