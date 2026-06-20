#include <bits/stdc++.h>
using namespace std;
// Divide two integers without using multiplication, division and mod operator
// Problem Statement: Given the two integers, dividend and divisor. Divide without using the mod, division,
//  or multiplication operators and return the quotient.
// The fractional portion of the integer division should be lost as it truncates toward zero.
// As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed
//  integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1
// , then return 231 - 1,
//  and if the quotient is strictly less than -231, then return -231.

// Brute Force -- using basic maths
// division = repetative substraction
int div2Integer(int dividend, int divisor)
{
    int cnt = 0;
    int sum = 0;
    while ((sum + divisor) <= dividend)
    {
        cnt++;
        sum += divisor;
    }

    return cnt;
    // TC = O(dividend) -- TLE
    // SC = O(1)
}

// Using idea of bit manipulation -- divisor*(sum of power of 2's)
int div2Integer2(int dividend, int divisor)
{
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    bool sign = true; // +ve

    if (dividend < 0 && divisor >= 0)
        sign = false;
    if (dividend >= 0 && divisor < 0)
        sign = false;

    long n = labs(dividend);
    long d = labs(divisor);

    long ans = 0;

    while (n >= d)
    {
        int cnt = 0;

        while (n >= d && (n >= d * (1LL << (cnt + 1))))
        {
            cnt++;
        }

        ans += (1LL << cnt);
        n = n - d * (1LL << cnt);
    }

    if (ans > (long)INT_MAX)
        return INT_MAX;
    if (ans < (long)INT_MIN)
        return INT_MIN;

    if (!sign)
        return -1 * ans;

    return ans;
    // TC = O(log(n)²)
    // SC = O(1)
}

// optimal solution logn -- ulta chala diya hain 31 to 0 tak jahan bhi n  >= (1<<i)*divisor ke 
// ane app hi minus ho jayega and ansver bhi add kar denge 1<<i ko
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long n = llabs(dividend);
    long long d = llabs(divisor);

    long long ans = 0;

    for(int i = 31; i >= 0; i--)
    {
        if(n >= (d << i))
        {
            ans += (1LL << i);
            n -= (d << i);
        }
    }

    if((dividend < 0) ^ (divisor < 0))
        ans = -ans;

    return ans;
    // TC = O(logN)
    // SC = O(logN)
}


int main()
{
    long n = INT_MAX;
    int d = 2;
    cout << "n = " << n << "\nd = " << d << "\n"
         << n << "/" << d << "= " << divide(n, d) << endl;
    return 0;
}