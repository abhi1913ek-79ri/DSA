#include <bits/stdc++.h>
using namespace std;
vector<long long> factorialNumbers(long long n)
{
    vector<long long> v;
    long long fact = 1; // Initial factorial value (0! = 1)
    int i = 1;

    while (fact <= n)
    {
        v.emplace_back(fact); // Add the factorial to the vector
        i++;
        fact *= i; // Compute the next factorial iteratively
    }
    return v;
}

int main()
{
    vector<long long> v;
    v=factorialNumbers(123);
    for(auto val:v ){
        cout<<val<<" ";
    }
    return 0;
}