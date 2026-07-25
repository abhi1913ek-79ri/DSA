#include <bits/stdc++.h>
using namespace std;
// Max product two digit of n
int maxProduct_brute(int n)
{
    vector<int> digits;
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    int maxi = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        for (int j = i + 1; j < digits.size(); j++)
        {
            maxi = max(maxi, digits[i] * digits[j]);
        }
    }

    return maxi;
    // TC = O(d*d) = O(100) = O(1)
    // Sc = O(d) = O(10) = O(1)
}


int maxProduct_optimal(int n){
    int first = 0;
    int second = 0;

    while (n)
    {
        int d = n%10;
        if(d>first){
            second = first;
            first = d;
        }else if(d>second){
            second = d;
        }
        n /= 10;
    }

    return first*second;
    // TC = O(d) = O(1)
    // SC = O(1)
}

int main()
{
    int n;
    cin >> n;
    cout << maxProduct_brute(n);
    return 0;
}